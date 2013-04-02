#include <stdio.h>
#include <unistd.h>

#include <signal.h>
#include <string.h>





int main()
{
    printf("Début du programme ==\n");
    
    sigset_t listeSignaux;
    sigset_t listeSignauxBloques;
    
    sigemptyset(&listeSignaux);
    sigaddset(&listeSignaux, SIGINT);
    sigaddset(&listeSignaux, SIGUSR1);
    
    
    // Bloquage du signal USR1 et INT.
    sigprocmask(SIG_BLOCK, &listeSignaux, NULL);
    sleep(15);
    
    
    // Réception des signaux.
    sigpending(&listeSignauxBloques);
    
    
    // Affichage du signal reçu.
    if (sigismember(&listeSignauxBloques, SIGUSR1))
    {
        printf("Signal USR1 envoyé !\n");
    }
    if (sigismember(&listeSignauxBloques, SIGINT))
    {
        printf("Signal INT envoyé !\n");
    }
    
    
    // Déblocage du signal USR1 et INT.
    printf("Déblocage des signaux.\n");
    sigprocmask(SIG_UNBLOCK, &listeSignaux, NULL);
    sleep(15);
    
    
    
    
    printf("Fin du programme ==\n");
    
    
    return 0;
}


