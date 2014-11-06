#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/types.h>

struct birthday {
  int day;
  int month;
  int year;
  struct list_head list;
};

static LIST_HEAD(birthday_list);

/* This function is called when the module is loaded. */
int simple_init(void)
{


       LIST_HEAD(listhead);
       struct birthday *ptr;
       struct birthday *person;

       struct birthday *othera;
       struct birthday *otherb;
       struct birthday *otherc;
       struct birthday *otherd;
       printk(KERN_INFO "Loading Module\n");
       person = kmalloc(sizeof(*person), GFP_KERNEL);
       person->day=2;
       person->month=8;
       person->year=1995;
       
       othera = kmalloc(sizeof(*othera), GFP_KERNEL);
       otherb = kmalloc(sizeof(*otherb), GFP_KERNEL);
       otherc = kmalloc(sizeof(*otherc), GFP_KERNEL);
       otherd = kmalloc(sizeof(*otherd), GFP_KERNEL);
       
       othera->day = 4;
       otherb->day = 27;
       otherc->day = 15;
       otherd->day = 20;
       othera->month = 9;
       otherb->month = 4;
       otherc->month = 3;
       otherd->month = 12;
       othera->year = 1974;
       otherb->year = 1958;
       otherc->year = 1948;
       otherd->year = 1990;
       



       INIT_LIST_HEAD(&person->list);
       INIT_LIST_HEAD(&othera->list);
       INIT_LIST_HEAD(&otherb->list);
       INIT_LIST_HEAD(&otherc->list);
       INIT_LIST_HEAD(&otherd->list);

       list_add_tail(&person->list, &birthday_list);
       list_add_tail(&othera->list, &birthday_list);
       list_add_tail(&otherb->list, &birthday_list);
       list_add_tail(&otherc->list, &birthday_list);
       list_add_tail(&otherd->list, &birthday_list);

       list_for_each_entry(ptr, &birthday_list, list){
         printk(KERN_INFO "Person %d-%d-%d\n", ptr->day, ptr->month, ptr->year);
       }


       return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	struct birthday *ptr, *next;
	printk(KERN_INFO "Removing Module\n");
	list_for_each_entry_safe(ptr, next, &birthday_list, list){
	  list_del(&ptr->list);
	  kfree(ptr);
	}
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

