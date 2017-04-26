/*
    这个是我自己实现的关闭本地cpu所有中断的 函数
    最终是使用内嵌汇编 调用 scpi 指令来关闭，
    Linux Kerenl中对应的函数 是 local_irq_disable()、disable_irq().
    
    
    1 : shield_irq_local()
    2 : shield_irq_num()
*/

