//已知由一个线性链表表示的线性表中含有三类字符的数据元素
//(如：字母字符、数字字符和其他字符)
//试编写算法将该线性表分割为三个循环链表
//其中每个循环链表表示的线性表中均只含一类字符。

#include "linearlinkedlist.h"
#include "cyclelinkedlist.h"
#include <iostream>

void Classification(Linear_Linked_List<char>&LLList, Cycle_Linked_List<char> &CLList_letter, Cycle_Linked_List<char> &CLList_Number, Cycle_Linked_List<char> & CLList_Others);

int main() {
	//初始化链表
	Linear_Linked_List<char> LLList('a');
	LLList.ListInsert(2, 'b');
	LLList.ListInsert(3, 'c');
	LLList.ListInsert(4, '3');
	LLList.ListInsert(5, ')');
	LLList.ListInsert(6, '4');
	LLList.ListInsert(7, '*');
	Cycle_Linked_List<char> CLList_letter;
	Cycle_Linked_List<char> CLList_Number;
	Cycle_Linked_List<char> CLList_Others;

	Classification(LLList, CLList_letter, CLList_Number, CLList_Others);
	system("pause");
}

void Classification(Linear_Linked_List<char> &LLList, Cycle_Linked_List<char>& CLList_letter, Cycle_Linked_List<char>& CLList_Number, Cycle_Linked_List<char>& CLList_Others)
{
	bool isFirst_Num = true;
	bool isFirst_Letter = true;
	bool isFirst_Other = true;

	for (int i = 0; i < LLList.ListLength(); i++)
	{
		if (LLList.GetElem(i + 1) >= '0'&&LLList.GetElem(i + 1) <= '9') {
			if (isFirst_Num)

			{
				CLList_Number.InitCycleList(LLList.GetElem(i + 1));
				isFirst_Num = false;
			}
			else
			{
				CLList_Number.CycleListInsert(2, LLList.GetElem(i + 1));
			}
		}
		else if ((LLList.GetElem(i + 1) >= 'A'&&LLList.GetElem(i + 1) <= 'Z') || (LLList.GetElem(i + 1) >= 'a'&&LLList.GetElem(i + 1) <= 'z'))
		{
			if (isFirst_Letter)
			{
				CLList_letter.InitCycleList(LLList.GetElem(i + 1));
				isFirst_Letter = false;
			}
			else
			{
				CLList_letter.CycleListInsert(2, LLList.GetElem(i + 1));

			}
		}
		else
		{
			if (isFirst_Other)
			{
				CLList_Others.InitCycleList(LLList.GetElem(i + 1));
				isFirst_Other = false;
			}
			else
			{
				CLList_Others.CycleListInsert(2, LLList.GetElem(i + 1));
			}
		}
	}
}
