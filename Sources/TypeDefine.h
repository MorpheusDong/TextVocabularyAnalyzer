#ifndef _TYPE_DEFINE_H_
#define _TYPE_DEFINE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <iterator>
#include <map>

using namespace std;

#define COCA_WORDS_NUM                       20201U
#define WORDS_HEAD_NUM                       26U
							                 
#define WORDS_HEAD_A                         0U
#define WORDS_HEAD_B                         1U
#define WORDS_HEAD_C                         2U
#define WORDS_HEAD_D                         3U
#define WORDS_HEAD_E                         4U
#define WORDS_HEAD_F                         5U
#define WORDS_HEAD_G                         6U
#define WORDS_HEAD_H                         7U
#define WORDS_HEAD_I                         8U
#define WORDS_HEAD_J                         9U
#define WORDS_HEAD_K                         10U
#define WORDS_HEAD_L                         11U
#define WORDS_HEAD_M                         12U
#define WORDS_HEAD_N                         13U
#define WORDS_HEAD_O                         14U
#define WORDS_HEAD_P                         15U
#define WORDS_HEAD_Q                         16U
#define WORDS_HEAD_R                         17U
#define WORDS_HEAD_S                         18U
#define WORDS_HEAD_T                         19U
#define WORDS_HEAD_U                         20U
#define WORDS_HEAD_V                         21U
#define WORDS_HEAD_W                         22U
#define WORDS_HEAD_X                         23U
#define WORDS_HEAD_Y                         24U
#define WORDS_HEAD_Z                         25U
							                 
#define USUAL_WORD_NUM                       17U


typedef enum WordFrequencyType
{
	WORD_UNDER_4000 = 0,
	WORD_4000_6000,
	WORD_6000_8000,
	WORD_8000_10000,
	WORD_10000_12000,
	WORD_12000_14000,
	WORD_14000_16000,
	WORD_OVER_16000,
	WORD_NOT_FOUND_COCA,
	WORD_LEVEL_NUM
}TagWordFrequencyType;

const string alphabet_str = "abcdefghijklmnopqrstuvwxyz";

const string report_str[WORD_LEVEL_NUM] = {
	"UNDER 4000: ",
	"4000-6000: ",
	"6000-8000: ",
	"8000-10000: ",
	"10000-12000: ",
	"12000-14000: ",
	"14000-16000: ",
	"16000-20000+: ",
	"\nNot found in COCA:"
};

//for usual words not included in COCA
const string usual_w_out_of_COCA_str[USUAL_WORD_NUM] =
{
	"s","is","are","re","was","were",
	"an","won","t","has","had","been",
	"did","does","cannot","got","men"
};


#endif

