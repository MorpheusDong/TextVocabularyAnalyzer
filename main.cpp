/* main .cpp */

#include <numeric>
#include <iomanip>
#include <ctime>
#include "TextVocabularyAnalyzer.h"

int main()
{
	//file init
	ifstream COCA_txt("D:\\COCA.txt");
	ifstream USER_txt("D:\\JobsSpeech.txt");

	//time init
	clock_t startTime, endTime;
	double build_map_time = 0;
	double process_time = 0;

	startTime = clock();    //build time start

	//build COCA words map
	map<string, int> COCA_WordsList[WORDS_HEAD_NUM];
	int readlines = 0;

	while (readlines < COCA_WORDS_NUM)
	{
		int frequency = 0; string word = "";
		COCA_txt >> frequency;
		COCA_txt >> word;

		//transform to lower uniformly 
		transform(word.begin(), word.end(), word.begin(), tolower);

		//import every word
		for (int whead = WORDS_HEAD_A; whead < WORDS_HEAD_NUM; whead++)
		{
			//check word head 
			if (word[0] == alphabet_str[whead])
			{
				//if a word already exists, only load its lower frequency
				if (COCA_WordsList[whead].find(word) == COCA_WordsList[whead].end())
				{
					COCA_WordsList[whead].insert(make_pair(word, frequency));
				}
				else
				{
					COCA_WordsList[whead][word] = frequency < COCA_WordsList[whead][word] ? frequency : COCA_WordsList[whead][word];
				}
			}
			else
			{
				// do nothing
			}
		}
		readlines++;
	}

	endTime = clock();    //build time stop
	build_map_time = (double)(endTime - startTime) / CLOCKS_PER_SEC;

	//user prompt
	cout << "COCA words list imported.\nPress any key to start frequency analysis...\n";
	cin.get();

	startTime = clock();    //process time start

	//find text words
	vector<char> content_read;
	CLetters word_readed;
	vector<int> frequecy_processed = { 0 };
	array<int, WORD_LEVEL_NUM> words_analysis_array{ 0 };
	char char_read = ' ';

	//get text char one by one
	while (USER_txt.get(char_read))
	{
		//only letters and '-' between letters will be received
		if (isaletter(char_read) || char_read == '-')
		{
			content_read.push_back(char_read);
		}
		else
		{
			//char which is not a letter marks the end of a word
			if (!content_read.empty())    //skip single letter 
			{
				int current_word_frequency = 0;

				//assign letters to make the word
				word_readed.fill(content_read);
				word_readed.processing();

				cout << "Frequency:";
				//check the word's head and find its frequency in COCA list
				for (int whead = WORDS_HEAD_A; whead < WORDS_HEAD_NUM; whead++)
				{
					if (word_readed.firstletter() == alphabet_str[whead])
					{
						cout << COCA_WordsList[whead][word_readed.word()];
						current_word_frequency = COCA_WordsList[whead][word_readed.word()];

						//check if the word has been processed
						if (current_word_frequency == 0)
						{
							//addtional check
							if (word_readed.usual_recheck())
							{
								word_frequency_analyze(words_analysis_array, WORD_UNDER_4000);
							}
							else if (word_readed.form_recheck())
							{
								current_word_frequency = COCA_WordsList[whead][word_readed.word()];    //try again
								if (current_word_frequency > 0)
								{
									frequecy_processed.push_back(current_word_frequency);
									word_frequency_analyze(words_analysis_array, frequency_classify(current_word_frequency));
								}
								else
								{
									// do nothing
								}
							}
							else
							{
								word_frequency_analyze(words_analysis_array, WORD_NOT_FOUND_COCA);
							}
						}
						else if (find(frequecy_processed.begin(), frequecy_processed.end(), current_word_frequency)
							== frequecy_processed.end())
						{
							//classify this word and make statistics
							frequecy_processed.push_back(current_word_frequency);
							word_frequency_analyze(words_analysis_array, frequency_classify(current_word_frequency));
						}
						else
						{
							// do nothing
						}
					}
					else
					{
						//do nothing
					}
				}
				cout << endl;

				content_read.clear();
			}
			else
			{
				//do nothing
			}
		}
	}

	endTime = clock();    //process time stop
	process_time = (double)(endTime - startTime) / CLOCKS_PER_SEC;

	//calc whole words processed
	int whole_words_analyzed = 0;
	whole_words_analyzed = accumulate(words_analysis_array.begin(), words_analysis_array.end(), 0);

	//report result
	cout << "\n////////// Report ////////// \n";
	for (int i = 0;i< words_analysis_array.size();i++)
	{
		cout << report_str[i] <<"\t"<< words_analysis_array[i] << " (";
		cout<<fixed<<setprecision(2)<<(float)words_analysis_array[i] * 100 / whole_words_analyzed << "%)" << endl;
	}
	cout << "\nWords totally analyzed: " << whole_words_analyzed << endl;

	//show run time
	cout << "Map build time: " << build_map_time*1000 << "ms.\n";
	cout << "Process time: " << process_time*1000 << "ms.\n";
	cout << "////////////////////////////" << endl;

	//close file
	COCA_txt.close();
	USER_txt.close();

	return 0;
}


