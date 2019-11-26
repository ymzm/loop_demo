#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main(){
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
    return 0;
}

/* mark all the timestamps in conn; used when conn is init */
void markConnStamp(conn_obj *connInfo)
{
    task_obj *taskObj;
    iop_list_node_t *taskNode;
    unsigned long start_time;
#ifdef __linux__
    struct timeval tv;
    gettimeofday(&tv,NULL);
    start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000; /* time in millisecond*/
#else

#endif
    if (conInfo == NULL)
    {
        printf("Error: Invalid conection\n");
	return;
    }

    taskNode = connInfo->task_list.head;
    while(taskNode)
    {
        taskObj = (task_obj)*taskNode->data;
        if (taskObj == NULL)
	{
	    printf("Error: Invalid task object in node\n");
	    break;
	}	
#ifdef __linux__
        taskObj->start_time =         

#else
#endif
    }




}
