typedef struct _sched_tree{
    
    unsigned int prio;
    
    struct _sched_tree * left;
    struct _sched_tree * right;
    
}SchedTree;
