#include "../Domain//Movie.h"
#include "../Validator/Validator.h"
#include "../Repository/Repository.h"
#include "../Repository/LabRepository.h"
#include "../Service/Service.h"
#include "../Exceptii/Exceptii.h"

class Teste{

private:

    /**
     * Ruleaza testele pentru toate functinonalitatiile din domain
     */
    static void Ruleaza_teste_domain();

    /**
     * Ruleaza testele pentru toate functinonalitatiile din validator
     */
    static void Ruleaza_teste_validator();

    /**
     * Ruleaza testele pentru toate functinonalitatiile din repository
     */
    static void Ruleaza_teste_repository();
    static void Ruleaza_teste_adauga_repo();
    static void Ruleaza_teste_cauta_repo();
    static void Ruleaza_teste_modifica_repo();
    static void Ruleaza_teste_sterge_repo();

    /**
     * Ruleaza testele pentru toate functinonalitatiile din repository
     */
    static void Ruleaza_teste_Labrepository();
    static void Ruleaza_teste_adauga_Labrepo();
    static void Ruleaza_teste_cauta_Labrepo();
    static void Ruleaza_teste_modifica_Labrepo();
    static void Ruleaza_teste_sterge_Labrepo();

    /**
     * Ruleaza testele pentru toate functinonalitatiile din service
     */
    static void Ruleaza_teste_service();
    static void Ruleaza_teste_adauga();
    static void Ruleaza_teste_cauta();
    static void Ruleaza_teste_modifica();
    static void Ruleaza_teste_sterge();
    static void Ruleaza_teste_filtrare_generica();
    static void Ruleaza_teste_sortare_generica();
    static void Ruleaza_teste_adauga_wishlist();
    static void Ruleaza_teste_goleste_wishlist();
    static void Ruleaza_teste_adauga__random_wishlist();
    static void Ruleaza_teste_salveaza_in_fisier_wishlist();
    static void Ruleaza_teste_yearStatitics();


    /**
     * Ruleaza testele pentru Undo
     */
    static void Ruleaza_teste_undo();



    /**
     * Ruleaza testele pentru exceptii
     */
    static void Ruleaza_teste_execeptii();

public:
    /**
    * Constructorul
    */
    Teste()=default;

    /**
     * Ruleaza toate testele pentru functionalitatiile din aplicatie
     */
    void Ruleaza_toate_testele() const;
};