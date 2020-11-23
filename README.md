# CPROG_Projekt
Uppgift för Cprog HT 2020

För Basnivå gäller följande krav:

   * programmet ska kodas i C++ och använda grafikbiblioteket SDL (närmare bestämt SDL2)
   * objektorienterad programmering ska användas: programmet ska vara uppdelad i klasser med användning av oo-tekniker som inkapsling, arv och polymorfism
   * tillämpningsprogrammeraren ska skyddas mot att göra svårupptäckta fel som att använda värdesemantik för objekt av polymorfa klasser
   * det ska finnas en gemensam basklass (säg Sprite) för alla figurer, denna basklass ska vara förberedd för att vara en rotklass i en klasshierarki (om tillämpningsprogrammet önskar göra subklasser till den)
   
   * inkapsling: datamedlemmar ska vara privata om inte väldigt speciella skäl föreligger
   * det ska inte finnas något minnesläckage, du ska se till att dynamiskt allokerat minne städas bort
   * spelmotorn ska kunna ta emot input (tangentbordshändelser, mushändelser) och reagera på dem enligt tillämpningsprogrammets önskemål, eller vidarebefordra dem till tillämpningens objekt
   
   * enkel kollisionsdetektering: man ska kunna kolla om den omgivande rektangeln för en Sprite har kolliderat med den omgivande rektangeln för en annan Sprite
   * programmet ska vara kompilerbart och körbart på en dator under både Linux och MS Windows (alltså inga plattformspecifika konstruktioner) med SDL 2 och SDL_ttf, SDL_image och SDL_mixer (Om man vill programmera med andra bibliotek kan man få dispens från detta krav men det kräver en överenskommelse med kursansvarige)
