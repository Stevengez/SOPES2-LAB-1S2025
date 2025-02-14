#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Steven Jocol");
MODULE_DESCRIPTION("Un módulo simple que imprime mensajes");
MODULE_VERSION("0.1");

static int __init hello_init(void) {
    printk(KERN_INFO "¡Hola, mundo! El módulo ha sido cargado.\n");
    return 0; // Devuelve 0 si se carga correctamente
}

static void __exit hello_exit(void) {
    printk(KERN_INFO "¡Adios, mundo! El modulo ha sido descargado\n");
}

module_init(hello_init);
module_exit(hello_exit);