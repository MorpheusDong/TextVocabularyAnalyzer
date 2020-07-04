#ifndef _TEXT_VOCABULARY_ANALYZER_H_
#define _TEXT_VOCABULARY_ANALYZER_H_

#include "TypeDefine.h"

extern TagWordFrequencyType frequency_classify(const int wfrq);
extern void word_frequency_analyze(array<int, WORD_LEVEL_NUM>& wfrq_array, TagWordFrequencyType wfrq_tag);
extern bool isaletter(const char& c);

class CLetters
{
private:
	string m_word;

public:
	CLetters();
	~CLetters();
	void fill(vector<char>& vw);
	const string word();
	const char firstletter();
	void processing();
	bool usual_recheck();
	bool form_recheck();
};



#endif // !_TEXT_VOCABULARY_ANALYZER_H_

