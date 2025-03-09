Øyvind: 
- fant noen bugs vi må fikse: 
    - hvis man trykker på stopp-knappen mellom 2 etasjer, for å deretter trykke på den forrige etasjen den var i vil ikke heisen kjøre dit fordi det var den siste etasjen den var i. 
    - får den for mange bestillinger vil ikke heisen kjøre noe sted, tror den sliter med å vite hva den skal gjøre hvis den ikke er i en bevegelsesretning eller hvis den får inn etasjer over og under.  

Tobias:
- lager void go_to_default(); //går til 3 etasje og lukker døren [FERDIG]
- lager int finn_neste_stopp() [FERDIG]
