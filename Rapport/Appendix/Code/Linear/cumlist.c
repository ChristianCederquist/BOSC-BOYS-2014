#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/types.h>



/* This function is called when the module is loaded. */
int listcum_init(void)
{
	struct task_struct *task;

	for_each_process(task){
	  printk(KERN_INFO "%s: State is %ld and process id is %d\n",task->comm,task->state,task->pid);
	}

       	printk(KERN_INFO "Loading Module\n");
	return 0;
}

/* This function is called when the module is removed. */
void listcum_exit(void) {
	printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( listcum_init );
module_exit( listcum_exit );

MODULE_LICENSE("DALARmusic");
MODULE_DESCRIPTION("List Module");
MODULE_AUTHOR("DALARmusic");

