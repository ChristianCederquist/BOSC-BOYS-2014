#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/sched.h>

int dfs_list(struct task_struct *task){
	struct list_head *list;	  
	struct task_struct *child;

  	list_for_each(list, &task->children){
	  child = list_entry(list, struct task_struct, sibling);	
	  printk(KERN_INFO "%s: State is %ld and process id is %d\n",child->comm,child->state,child->pid);
	  dfs_list(child);
        }
	
  return 0;
}

/* This function is called when the module is loaded. */
int listdfs_init(void)
{
       	printk(KERN_INFO "Loading Module\n");
	dfs_list(&init_task);

	return 0;
}

/* This function is called when the module is removed. */
void listdfs_exit(void) {
	printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( listdfs_init );
module_exit( listdfs_exit );

MODULE_LICENSE("DELERmusic");
MODULE_DESCRIPTION("DFS Module");
MODULE_AUTHOR("DELERmusic");

