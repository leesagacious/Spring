typedef struct _sched_tree{
    
    unsigned int  prio;
    unsigned long vir_time;
    unsigned long total_run_time;	
    
    struct _sched_tree * left;
    struct _sched_tree * right;
    
}sched_tree;

static struct kmem_cache * sched_tree_cache;

int __init sched_tree_init_cache(void)
{
    sched_tree_cache = kmem_cache_create("sched_tree_cache",sizeof(sched_tree),0, 
                                         (SLAB_RECLAIM_ACCOUNT|SLAB_MEM_SPREAD),NULL);
    if (!sched_tree_cache){
	  return -ENOMEM;
    }
    
    return 0;
}

int relatively(unsigned int original_node_vir_time,unsigned int new_node_prio)
{
    return original_node_vir_time > new_node_prio;
}  

void insertSchedTree(sched_tree ** source,int ( * relatively )(unsigned int,unsigned int))
{
    sched_tree * tree_node = kmem_cache_alloc(sched_tree_cache,GFP_KERNEL);
    if (!tree_ode){
        pr_err("kmem_cache_alloc has failure\n");
        return;
    }
    
    tree_node->left  = NULL;
    tree_node->right = NULL;
    tree_node->prio  = 10;
    tree_node->vir_time = 10;	
    
    if (*source == NULL){
        *source = tree_node;
        return;
    }
    
    while (1)
    {
            if (relatively(*source->prio,prio) > 0)   //比较.
            {
                if ((*source)->left){            //如果左子节点非空
                    *source = (*root)->left;     //查找下一个左子节点
                }else {
                    (*source)->left = node;     // 添加 
                    break;
                }
            }
            else 
            {
                if ((*source)->right)
                {
                    *source = (*source)->right;
                }else {
                    (*source)->right = node;
                    break;
                }
            }    
    } 
}
