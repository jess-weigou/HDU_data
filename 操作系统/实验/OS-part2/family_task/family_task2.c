#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/pid.h>

#include<linux/types.h>
#include<linux/sched.h>
#include<linux/list.h>
#include<linux/moduleparam.h>

static int pid;
module_param(pid, int ,0644);

static int show_family_init(void)
{
	struct pid * kpid;
	struct task_struct * task;
	struct task_struct *parent;

	struct list_head *p_sibling;
	struct task_struct *sibling_task;

	struct list_head *p_children;
	struct task_struct *children_task;

	kpid = find_get_pid(pid);
	task = pid_task(kpid, PIDTYPE_PID);

	printk(KERN_ALERT"show_family_init() begin");

	//父进程
	printk(KERN_ALERT"parent process:\n");

	parent = task->parent;
	printk(KERN_ALERT"parent->comm parent->pid patent->state\n");
	printk(KERN_ALERT"%20s %5d %5ld\n",parent->comm,parent->pid,parent->state);
	//兄弟进程
	printk(KERN_ALERT"brother process:\n");
	printk(KERN_ALERT"sibling_task->comm sibling_task->pid sibling_task->state\n");
	list_for_each(p_sibling,&(task->sibling))
	{
		// 为了不找兄弟链表的头部
		if(p_sibling != &task->parent->children)
		{
			sibling_task=list_entry(p_sibling,struct task_struct,sibling);
			//if(sibling_task->pid != task->parent->children->pid)
    			printk(KERN_ALERT"%20s %5d %5ld\n",sibling_task->comm,sibling_task->pid,sibling_task->state);
		}
	}
	//子进程
	printk(KERN_ALERT"children process:\n");
	printk(KERN_ALERT"children_task->comm children_task->pid children_task->state\n");
	list_for_each(p_children,&(task->children))
	{
		children_task=list_entry(p_children,struct task_struct,sibling);
    		printk("%20s %5d %5ld\n",children_task->comm,children_task->pid,children_task->state);
	}
	
	return 0;
}
static void show_family_exit(void)
{
	printk(KERN_ALERT"show_family_init() has exited\n");
}
module_init(show_family_init);
module_exit(show_family_exit);

MODULE_LICENSE("GPL");
