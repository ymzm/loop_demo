#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include "self_define.h"



/* mark all the timestamps in conn; used when conn is init */
void markConnStamp(conn_obj *connInfo)
{
    task_obj *taskObj;
#ifdef __linux__
    dlist_node_t *taskNode; 
#else
    iop_list_node_t *taskNode;
#endif
    unsigned long start_time;
#ifdef __linux__
    struct timeval tv;
#else

#endif
    if (connInfo == NULL)
    {
        printf("Error: Invalid conection\n");
	return;
    }

    taskNode = connInfo->task_list.head;
    while(taskNode)
    {
#ifdef __linux
        taskObj = (task_obj *)taskNode;
#else
        taskObj = (task_obj)*taskNode->data;
#endif
        if (taskObj == NULL)
	{
	    printf("Error: Invalid task object in node\n");
	    break;
	}	
#ifdef __linux__
    gettimeofday(&tv,NULL);
    start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000; /* time in millisecond*/
        taskObj->start_time = start_time;       
     usleep(1000);
#else
#endif
	taskNode =  taskNode->next;
    }

}


int test_markConnStamp(void)
{
    int i;
    conn_obj connInfo;
    DLIST_INIT(&(connInfo.task_list));
    
    task_obj objs[100] = {0};
    for (i=0; i<100; i++)
    {
        DLIST_ADD(&(connInfo.task_list), &(objs[i]));
    }
    
    markConnStamp(&connInfo);
    for (i=0; i<100; i++)
    {
        printf("%d -- %ld\n", i, objs[i].start_time);
    }
    return 0;
}

int main(){
#if 0
    struct timeval tv;
    gettimeofday(&tv,NULL);
    printf("second:%ld\n",tv.tv_sec);  //秒
    printf("millisecond:%ld\n",tv.tv_sec*1000 + tv.tv_usec/1000);  //毫秒
    printf("microsecond:%ld\n",tv.tv_sec*1000000 + tv.tv_usec);  //微秒

    sleep(3); // 为方便观看，让程序睡三秒后对比
    printf("3s later:\n");

    gettimeofday(&tv,NULL);
    printf("second:%ld\n",tv.tv_sec);  //秒
    printf("millisecond:%ld\n",tv.tv_sec*1000 + tv.tv_usec/1000);  //毫秒
    printf("microsecond:%ld\n",tv.tv_sec*1000000 + tv.tv_usec);  //微秒
#endif
    test_markConnStamp();
    return 0;
}
