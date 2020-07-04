/* TextVocabularyAnalyzer.cpp */

#include <algorithm>
#include "TextVocabularyAnalyzer.h"

TagWordFrequencyType frequency_classify(const int wfrq)
{
	if (wfrq == 0)
	{
		return WORD_NOT_FOUND_COCA;
	}
	else if (wfrq > 0 && wfrq <= 4000)
	{
		return WORD_UNDER_4000;
	}
	else if (wfrq > 4000 && wfrq <= 6000)
	{
		return WORD_4000_6000;
	}
	else if (wfrq > 6000 && wfrq <= 8000)
	{
		return WORD_6000_8000;
	}
	else if (wfrq > 8000 && wfrq <= 10000)
	{
		return WORD_8000_10000;
	}
	else if (wfrq > 10000 && wfrq <= 12000)
	{
		return WORD_10000_12000;
	}
	else if (wfrq > 12000 && wfrq <= 14000)
	{
		return WORD_12000_14000;
	}
	else if (wfrq > 14000 && wfrq <= 16000)
	{
		return WORD_14000_16000;
	}
	else
	{
		return WORD_OVER_16000;
	}
}

void word_frequency_analyze(array<int, WORD_LEVEL_NUM>& wfrq_array, TagWordFrequencyType wfrq_tag)
{
	switch (wfrq_tag)
	{
	case WORD_UNDER_4000:
	{
		wfrq_array[WORD_UNDER_4000] += 1;
		break;
	}
	case WORD_4000_6000:
	{
		wfrq_array[WORD_4000_6000] += 1;
		break;
	}
	case WORD_6000_8000:
	{
		wfrq_array[WORD_6000_8000] += 1;
		break;
	}
	case WORD_8000_10000:
	{
		wfrq_array[WORD_8000_10000] += 1;
		break;
	}
	case WORD_10000_12000:
	{
		wfrq_array[WORD_10000_12000] += 1;
		break;
	}
	case WORD_12000_14000:
	{
		wfrq_array[WORD_12000_14000] += 1;
		break;
	}
	case WORD_14000_16000:
	{
		wfrq_array[WORD_14000_16000] += 1;
		break;
	}
	case WORD_OVER_16000:
	{
		wfrq_array[WORD_OVER_16000] += 1;
		break;
	}
	default:
	{
		wfrq_array[WORD_NOT_FOUND_COCA] += 1;
		break;
	}
	}
}

bool isaletter(const char& c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return true;
	}
	else
	{
		return false;
	}
}


//Class Cletters realization
CLetters::CLetters()
{
	m_word = "";
}

CLetters::~CLetters()
{
	//do nothing
}

void CLetters::fill(vector<char>& vw)
{
	//store the word with lower form
	m_word.assign(vw.begin(), vw.end());
	transform(m_word.begin(), m_word.end(), m_word.begin(), tolower);
}

const string CLetters::word()
{
	return m_word;
}

const char CLetters::firstletter()
{
	return m_word[0];
}

void CLetters::processing()
{
	cout << "Finding word \"" << m_word << "\"...\t";
}


bool CLetters::usual_recheck()
{
	//check if the word is usual
	bool RetVal = false;
	for (int i = 0; i < USUAL_WORD_NUM; i++)
	{
		if (m_word == usual_w_out_of_COCA_str[i])
		{
			RetVal = true;
		}
		else
		{
			//do nothing
		}
	}
	return RetVal;
}

bool CLetters::form_recheck()
{
	bool RetVal = false;
	if (m_word.length() > 3)
	{
		char e1, e2, e3;
		e3 = m_word[m_word.length() - 3];    //last but two letter
		e2 = m_word[m_word.length() - 2];    //last but one letter
		e1 = m_word[m_word.length() - 1];    //last letter

		if (e1 == 's')
		{
			m_word.erase(m_word.length() - 1);
			RetVal = true;
		}
		else if (e2 == 'e' && e1 == 'd')
		{
			m_word.erase(m_word.length() - 1);
			m_word.erase(m_word.length() - 1);
			RetVal = true;
		}
		else if (e3 == 'i' && e2 == 'n' && e1 == 'g')
		{
			m_word.erase(m_word.length() - 1);
			m_word.erase(m_word.length() - 1);
			m_word.erase(m_word.length() - 1);
			RetVal = true;
		}
		else
		{
			//do nothing
		}
	}
	return RetVal;
}
