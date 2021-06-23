#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/sched/signal.h>

static int show_all_process_init(void)
{
 	struct task_struct *p;
	p=NULL;
	printk(KERN_ALERT"show_all_process_init() begin");
	for_each_process(p){
        if(p->mm==NULL)
        {
    		printk(KERN_ALERT"%20s %5d %5ld %5d %5d\n",p->comm,p->pid, p->state,p->prio,p->parent->pid);
        }
    	}
	printk(KERN_ALERT"\n");
	return 0;
}
static void show_all_process_exit(void)
{
	printk(KERN_ALERT"show_all_process_init() has exited\n");
}
module_init(show_all_process_init);
module_exit(show_all_process_exit);

MODULE_LICENSE("GPL");
