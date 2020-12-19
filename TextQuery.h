// TextQuery.h
#pragma once
#include<fstream>
#include<memory>
#include<sstream>
#include<vector>
#include<set>
#include<string>
#include<map>


using line_no = std::vector<std::string>::size_type;

class QueryResult;

class TextQuery 
{
public:
	TextQuery(std::ifstream& is);
	QueryResult query(const std::string &) const;

private:
	std::shared_ptr<std::vector<std::string>> file;
	// �洢ÿ�����ʶ�Ӧ���кţ��к���set�洢��map��ָ�����ָ��
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};


class QueryResult 
{
friend std::ostream& print(std::ostream& os, const QueryResult& qr);

public:
	QueryResult(std::string s,
		std::shared_ptr<std::set<line_no>>p,
		std::shared_ptr<std::vector<std::string>>f):
		sought(s),lines(p), file(f){};
private:
	// �洢��ѯ���Ľ�������ݽ����
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

