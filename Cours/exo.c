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
    sigaddset(&listeSignaux, SIGUSR2);
    
    
    // Bloquage du signal USR2 et INT.
    sigprocmask(SIG_BLOCK, &listeSignaux, NULL);
    sleep(15);
    
    
    // Réception des signaux.
    sigpending(&listeSignauxBloques);
    
    
    // Affichage du signal reçu.
    if (sigismember(&listeSignauxBloques, SIGUSR2))
    {
        printf("Signal USR2 envoyé !\n");
    }
    if (sigismember(&listeSignauxBloques, SIGINT))
    {
        printf("Signal INT envoyé !\n");
    }
    
    
    // Déblocage du signal USR2 et INT.
    printf("Déblocage des signaux.\n");
    sigprocmask(SIG_UNBLOCK, &listeSignaux, NULL);
    sleep(15);
    
    
    
    
    printf("Fin du programme ==\n");
    
    
    return 0;
}


