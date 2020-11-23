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
   
   
   Spelet skall ha följande egenskaper(krav):

   * Spelet ska simulera en värld som innehåller olika typer av objekt. Objekten ska ha olika beteenden och röra sig i världen och agera på olika sätt när de möter andra objekt.
   * Det måste finnas minst två olika typer av objekt och det ska finnas flera instanser av minst en av dessa. T.ex ett spelarobjekt och många instanser av fiendeobjekt.
   * Ett beteende som måste finnas med är att figurerna ska röra sig över skärmen. Rörelsen kan följa ett mönster och/eller vara slumpmässig.
   * Det räcker att grafiken är tvådimensionell (för enkelhetens skull).
   * Världen (spelplanen) kan antas vara lika stor som fönstret (du kan göra en större spelplan med panorering, men det blir lite krångligare).
   * En figur ska styras av spelaren, med tangentbordet eller med musen. Du kan även göra ett spel där man spelar två stycken genom att dela på tangentbordet (varje spelare använder olika tangenter). Då styr man var sin figur.
   
   * Det ska hända olika saker när objekten möter varandra, de ska påverka varandra på något sätt. T.ex kan ett av objekten tas bort, eller så kan objek-ten förvandlas på något sätt, eller så kan ett nytt objekt skapas. (Ett exempel på att skapa/ta bort objekt är när man i Space Invaders trycker på skjuta- knappen, t.ex en musknapp, då avfyras ett laserskott och skottet blir då en ny figur som skapas och placeras i världen, på en position vid laserkanonens mynning. Skottet rör sig framåt (uppåt) och om det träffar ett fiendeskepp tas både skottet och skeppet bort, om skottet kommer utanför spelplanen, dvs det missar, tas endast skottet bort.
