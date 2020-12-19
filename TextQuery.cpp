//TextQuery.cpp
#include"TextQuery.h"

using namespace std;

TextQuery::TextQuery(ifstream &is)// ����һ���ļ������� 
{
	file = make_shared<vector<string>>();
	string text;
	while (getline(is, text))
	{
		//��ȡÿһ�д���vector
		file->push_back(text);
		int n = file->size() - 1; // ��ǰ�к�
		// �����ʺ�line���� map
		istringstream line(text);
		string word;
		while (line >> word) {
			shared_ptr<set<line_no>> & lines = wm[word]; // ����ָ��ָ��word
			if (!lines)//���ǵ�һ������wordָ��Ϊ��
			{
				lines.reset(new set<line_no>); // ����һ���µ�set
			}
			lines->insert(n);
		}

	}
}

QueryResult TextQuery::query(const string& sought) const 
{
	// ����һ����ѯ�ĵ��ʣ�����һ����ѯ�����
	// �Ƿ��иõ���,û�е�������Ҳ���з��أ� һ����̬�����ǿ��Է��ص�
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	// ʹ��find�����Ƿ���ڸõ���
	auto loc = wm.find(sought); // Ӧ����һ��ָ��
	if (loc != wm.end()) {
		// ����
		return QueryResult(sought, loc->second, file); // ��������ָ�룬������һ
	}
	else {
	// ������
		return QueryResult(sought, nodata, file);
	}

	
}


