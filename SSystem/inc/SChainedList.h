#ifndef __SChainedList_0_00_001
#define __SChainedList_0_00_001


template <class T>
struct	SChainedListEntry
{
	SChainedListEntry<T>*	previousEntry;
	SChainedListEntry<T>*	nextEntry;
	T						data;
};


template <class T>
class	SChainedList
{
private:
	int						nEntries;
	SChainedListEntry<T>*	first;
	SChainedListEntry<T>*	last;
	
	SChainedListEntry<T>*	find(const T value);
	
public:
	SChainedList()					:	nEntries(0), first(0), last(0)	{}
	SChainedList(const T value)		:	nEntries(0), first(0), last(0)	{add(value);}
	~SChainedList();
	
	void	add(const T value);
	void	remove(const T value);
};




template <class T>
SChainedListEntry<T>*	SChainedList<T>::find(const T value)
{
	SChainedListEntry<T>*	actualEntry=first;
	if(actualEntry->data == value)
		return actualEntry;
	while(actualEntry->nextEntry)
	{
		actualEntry=actualEntry->nextEntry;
		if(actualEntry->data == value)
			return actualEntry;
	}
	return 0;
}


template <class T>
SChainedList<T>::~SChainedList()
{
	//TO DO
	//delete all
}


template <class T>
void	SChainedList<T>::add(const T value)
{
	SChainedListEntry<T>*	newEntry			= new SChainedListEntry<T>();
							newEntry->data		= value;
							newEntry->nextEntry	= 0;
	
	nEntries++;
	
	if(nEntries)
	{
		newEntry->previousEntry	= last;
		last->nextEntry			= newEntry;
		last					= newEntry;
		return;
	}
	
	newEntry->previousEntry	= 0;
	first					= newEntry;
	last					= newEntry;
}

template <class T>
void	SChainedList<T>::remove(const T value)
{
	SChainedListEntry<T>*	entry	= find(value);
	
	if(!entry)
		return;
	
	if(entry->previousEntry)
		entry->previousEntry->nextEntry	= entry->nextEntry;
	else
		first	= entry->nextEntry;
	if(entry->nextEntry)
		entry->nextEntry->previousEntry	= entry->previousEntry;
	else
		last	= entry->previousEntry;
		
	delete	entry;
	nEntries--;
}


#endif

