#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

//Job : 작업 ID, 인쇄 요청을 한 사용자 이름, 인쇄 페이지 수
//Print : 새 인쇄 작업 추가, 현재까지 추가된 모든 인쇄 작업 처리
//Printer : 모든 지연되고 있는 인쇄 요청을 저장, 저장 순서는 먼저 요청된 순서대로
// 여러 사람이 프린터에 작업을 추가하는 시나리오를 구현하고, 프린터는 차례대로 인쇄 작업 수행

class Job
{
	std::wstring otherName;
	int totalPages;

public:
	Job(std::wstring name, int pages) : otherName(name), totalPages(pages)
	{ 
		static int id; id++; 
	}

	void Complete()
	{
		wcout << otherName << ": " << totalPages << "page Complete!" << endl;
	}
};

class Human
{
	std::wstring name;

public:
	Human(std::wstring name) : name(name) {}
	Job CreateJob(int pages) { return Job{ name, pages }; }
};

class Printer
{
	std::queue<Job> workList;

public:
	void Print(const Job& job)
	{
		workList.push(job);
	}

	bool operator()() {
		workList.front().Complete();
		workList.pop();
		return workList.size();
	}
};

int main()
{
	std::locale::global(std::locale("korean"));
	Human h1(L"민철");
	Human h2(L"민지");
	Human h3(L"민주");

	Printer printer;

	printer.Print(h1.CreateJob(13));
	printer.Print(h2.CreateJob(50));
	printer.Print(h3.CreateJob(188));
	printer.Print(h1.CreateJob(9));
	printer.Print(h3.CreateJob(1));

	while (printer()) {}
}
