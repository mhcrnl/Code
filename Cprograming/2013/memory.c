#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

void initMemory(Memory *memory, int length)
{
	memory->start=0;
  memory->end=length;
	memory->next=NULL;
  return;
}

void printMemory(Memory *memory)
{
  printf("==========\n");
  Memory *m_now;
  m_now=memory;
  while(m_now!=NULL)
  { 
	  if(m_now->end - m_now->start != 0) printf("start %d, length %d\n",m_now->start,m_now->end-m_now->start);
    m_now=m_now->next;
  }
	return;
}

void allocateMemory(Memory *memory, int start, int length)
{
  Memory *m_now;
  m_now=memory;
  while(m_now!=NULL)
  {
    if(m_now->start <= start && m_now->end >= start+length)
    {
      Memory *m_tmp;
      m_tmp=(Memory*)malloc(sizeof(Memory));
      initMemory(m_tmp,0);
      m_tmp->start=start+length;
      m_tmp->end=m_now->end;
      m_tmp->next=m_now->next;
      m_now->next=m_tmp;
      m_now->end=start;
      break;
    }
    m_now=m_now->next;
  }
  m_now = memory;
  while(m_now->next != NULL)
  {
    if(m_now->next->end - m_now->next->start == 0)
    {
      Memory *pre;
      pre = m_now->next;
      m_now->next = m_now->next->next;
      free(pre);
    }
    else m_now = m_now->next;
  }
	return;
}

void freeMemory(Memory *memory, int start, int length)
{
	Memory *m_now;
  m_now=memory;
  while(m_now->next != NULL)
  {
    if(m_now->end <= start && m_now->next->start >= start+length)
    {
      Memory *m_tmp;
      m_tmp=(Memory*)malloc(sizeof(Memory));
      initMemory(m_tmp,0);
      m_tmp->start=start;
      m_tmp->end=start+length;
      m_tmp->next=m_now->next;
      m_now->next=m_tmp;
      break;
    }
    m_now=m_now->next;
  }
  if(m_now->next == NULL && m_now->end <= start)
  {
    Memory *m_tmp;
    m_tmp = (Memory*)malloc(sizeof(Memory));
    initMemory(m_tmp, 0);
    m_tmp->start = start;
    m_tmp->end = start+length;
    m_now->next = m_tmp;
  }
  m_now = memory;
  while(m_now->next != NULL)
  {
    if(m_now->end == m_now->next->start)
    {
      Memory *pre;
      pre = m_now->next;
      m_now->end = m_now->next->end;
      m_now->next = m_now->next->next;
      free(pre);
    }
    else m_now = m_now->next;
  }
	return;
}
