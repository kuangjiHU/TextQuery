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
	// 存储每个单词对应的行号，行号用set存储，map存指向其的指针
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
	// 存储查询到的结果的数据结果，
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

