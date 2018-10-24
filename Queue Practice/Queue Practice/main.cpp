#include <iostream>
#include "QueueList.h"
int main()
{
	// This will check for memory leaks.  They will show up in your
		// output window along with the line number.  Replace the 
		// -1 argument in the second call with the allocation number
		// and then trace back through the call stack to find the leak.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(165);

	QueueList<int> list;
	list.Enqueue(0);
	list.Enqueue(1);
	list.Enqueue(2);
	list.DisplayAll();
	QueueList<int> list2;
	list2 = list;
	list2.DisplayAll();

	std::cout << std::endl << std::endl;
	system("pause");
	return 0;
}