#pragma once

#include "gen_common.h"

class VectorGenerator {
public:
					VectorGenerator() {}
					~VectorGenerator() {}

	void			Generate( const genType_t type, const uint32_t numComponents, const genFlags_t genFlags );

	void			PrintHeader() const;
	void			PrintInl() const;

private:
	std::string		m_codeHeader;
	std::string		m_codeInl;

	std::string		m_fullTypeName;
	std::string		m_typeString;

	genType_t		m_type;
	uint32_t		m_numComponents;

	genFlags_t		m_genFlags;

private:
	void			GenerateHeader();
	void			GenerateInl();

private:
	void			HeaderGenerateForwardDeclarations();
	void			HeaderGenerateMembers();
	void			HeaderGenerateMembersStruct( const std::string& componentNames );

	void			HeaderGenerateConstructors();
	void			HeaderGenerateOperatorsAssignment();
	void			HeaderGenerateOperatorsArithmetic();
	void			HeaderGenerateOperatorsArray();
	void			HeaderGenerateOperatorsEquality();
	void			HeaderGenerateOperatorsRelational();

	void			InlGenerateConstructors();
	void			InlGenerateOperatorsAssignment();
	void			InlGenerateOperatorsArithmetic();
	void			InlGenerateOperatorsArray();
	void			InlGenerateOperatorsEquality();
	void			InlGenerateOperatorsRelational();
};
