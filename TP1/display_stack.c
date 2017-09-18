static void * value_esp;
static void * value_ebp;

int main(){
    int i = 0;
    
    printf("Fonction Boucle basique \n");
    for(i; i < 10; i++)
        display_stacks();
       
    printf("Fonction Recurcive \n"); 
    fct_recurcive(0);
}

void display_stacks(){
    asm("movl %%esp, %0": "=r"(value_esp):);
    asm("movl %%ebp, %0": "=r"(value_ebp):);
    
    printf("esp : %d \n", value_esp);
    printf("ebp : %d \n", value_ebp);
}

int fct_recurcive(int v){
    display_stacks();
    if(v > 10)
        return 0;
    else
        fct_recurcive(++v);
}

