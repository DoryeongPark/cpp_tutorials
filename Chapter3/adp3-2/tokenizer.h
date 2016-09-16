#pragma once

#include <string>
#include <iostream>
#include <vector>

/*
*  tokenize
*  �Ű� ���� : str(���ڿ� ����) / tokens(���� ���ڿ��� ������ ������ ����) / delemeters (���� ����)
*  ���� : ���ڿ� ������ ���� ���ڷ� ���� ���ڿ��� ������ ��ȯ�Ͽ� ���Ϳ� �����Ѵ�.
*/
void tokenize(const std::string& str, std::vector<int>& tokens, const std::string& delimiters = " ")
{
	int lastPos = str.find_first_not_of(delimiters, 0);
	//�����ڰ� �ƴ� ù ��° ������ �ε���
	int pos = str.find_first_of(delimiters, lastPos);
	//��ġ lastPos�� ���� �����ڸ� ã�� �������� �ε����� ��´�.

	std::string token;//�� ��ū

	while (std::string::npos != pos || std::string::npos != lastPos)
		//�� pos�� npos�� ��� ������ ��� ���� �ƴ� ���� ������ ����
	{
		token = str.substr(lastPos, pos - lastPos);
		//lastPos���� pos - lastPos ��ġ ������ ���ڿ��� �����.
		tokens.push_back(stoi(token));
		//���������� ��ȯ�Ͽ� ���Ϳ� �����Ѵ�.
		lastPos = str.find_first_not_of(delimiters, pos);
		//lastPos�� pos�κ��� Ž���Ͽ� �����ڰ� �ƴ� ù ��° ������ ��ġ�� �����Ѵ�. 
		pos = str.find_first_of(delimiters, lastPos);
		//pos�� lastPos�κ��� Ž���Ͽ� �����ڰ� �˻��� ��ġ�� �����Ѵ�.
	}
}

