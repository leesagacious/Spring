#define CHECK_PROCESS_STATE (m)\
	do\
	{\
		long timeout = m * HZ / 1000;\
		while (timeout > 0)\
		{\
			timeout = schedule_timeout(timeout);\
		}\
	}while(0);
	

static struct task_struct * kThread = NULL;

static int testFunction(void * arg)
{
	char * mydata = kzalloc(strlen(arg) + 1 ,GFP_KERNEL);
	if (!mydata)
		return -ENOMEM;
	strncpy(mydata,arg,strlen(arg));

	while (!kthread_should_stop()){

		CHECK_PROCESS_STATE(1000);
		printk("%s\n",mydata);
	}

	kfree(mydata);

	return 0;
}

static int __init test_init(void)
{
	kThread = ktrhead_run(testFunction,"leesagacious","testKernelProcess");
	if (!IS_ERR(kThread))
		return PTR_ERR(kThread);
	return 0;
}

static void __exit test_exit(void)
{
	if (kThread){
		printk("test_exit\n");
		kthread_stop(kThread);
	}
}

module_init(test_init);
module_exit(test_exit);
MODULE_LICENSE("GPL");
