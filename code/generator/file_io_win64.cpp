/*
===========================================================================

HLML Generator.
Copyright (c) Dan Moody 2018 - Present.

This file is part of the HLML Generator.

The HLML Generator is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

The HLML Generator is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with The HLML Generator.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/
#ifdef _WIN32

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "file_io.h"

#define WIN32_LEAN_AND_MEAN 1
#include <Windows.h>

#include <stdio.h>
#include <assert.h>

#ifdef _DEBUG
#define WIN64_ASSERT( x ) \
	do { \
		if ( !(x) ) { \
			u32 error = GetLastError(); \
			LPSTR msgbuf = NULL; \
			FormatMessageA( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, \
							NULL, error, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ), (LPSTR) &msgbuf, 0, NULL ); \
			printf( "WIN64: %s failed at %s:%d: %s", #x, __FILE__, __LINE__, msgbuf ); \
\
			LocalFree( msgbuf ); \
\
			assert( false ); \
		} \
	} while ( 0 )
#else
#define WIN64_ASSERT( x ) x
#endif // _DEBUG

static HANDLE OpenOrCreateFileInternal( const char* filename ) {
	assert( filename );

	DWORD disposition = CREATE_ALWAYS;
	// DWORD flagsAndAttributes = FILE_FLAG_OVERLAPPED;
	DWORD flagsAndAttributes = 0;

	HANDLE handle = CreateFileA( filename, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, disposition, flagsAndAttributes, NULL );
	WIN64_ASSERT( handle != NULL );

	return handle;
}

static void CloseFileInternal( const HANDLE file ) {
	WIN64_ASSERT( CloseHandle( file ) );
}


void FS_WriteEntireFile( const char* filename, const char* data, const size_t length ) {
	assert( filename );
	assert( data );
	assert( length );

	HANDLE file = OpenOrCreateFileInternal( filename );

	DWORD bytesWritten = 0;
	WIN64_ASSERT( WriteFile( file, data, (DWORD) length, &bytesWritten, NULL ) );

	assert( bytesWritten == length );

	CloseFileInternal( file );
}

void FS_CreateFolder( const char* name ) {
	assert( name );

	if ( FS_FolderExists( name ) ) {
		return;
	}

	SECURITY_ATTRIBUTES secattr = {};
	WIN64_ASSERT( CreateDirectory( name, &secattr ) );
}

void FS_DeleteFolder( const char* name ) {
	assert( name );

	FS_DeleteAllFilesInFolder( name );

	// actually delete the folder
	WIN64_ASSERT( RemoveDirectory( name ) );
}

bool32 FS_FolderExists( const char* name ) {
	assert( name );

	DWORD attribs = GetFileAttributes( name );

	return ( attribs != INVALID_FILE_ATTRIBUTES ) && ( ( attribs & FILE_ATTRIBUTE_DIRECTORY ) != 0 );
}

void FS_DeleteAllFilesInFolder( const char* name ) {
	assert( name );

	bool32 shouldClose = false;

	// delete all folder contents
	char filename[128] = {};
	snprintf( filename, 128, "%s\\*", name );

	WIN32_FIND_DATA info = {};
	HANDLE handle = FindFirstFile( filename, &info );
	do {
		if ( info.cFileName[0] != 0 && info.cFileName[0] != '.' ) {
			snprintf( filename, 128, "%s\\%s", name, info.cFileName );
			WIN64_ASSERT( DeleteFile( filename ) );

			shouldClose = true;
		}
	} while ( FindNextFile( handle, &info ) );

	if ( shouldClose ) {
		WIN64_ASSERT( FindClose( handle ) );
	}
}

#undef WIN64_ASSERT

#endif // _WIN32