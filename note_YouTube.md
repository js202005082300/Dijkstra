#Algo de DIJKSTRA

Cours d'informatique : Algorithme de Dijkstra (2/4).
Auteure : Katia BARRE, professeure en CPGE au lycée Lesage (Vannes)
Source : [2 DIJKSTRA algorithme et preuve](https://www.youtube.com/watch?v=AtFtWhfnCsM)

## Notation
Graphe = (sommets, arcs)
poids : arcs -> R+ la fonction de pondération
s le sommet d'origine

Pour un sommet u:
$\phi[u]$ la longueur d'un plus court chemin de s à u
convention : $\phi[u] = +\infty$ lorsqu'il n'y a aucun dchemin de s à u
Objectif : pour tout sommet u, déterminer la valeur de $\phi[u]$ et un plus court chemin de s à u

successeurs(u) l'ensemble des successeurs de u:
successeurs(u)={v ∈ Sommets, (u,v) ∈ Arcs}

Qui varient au cours du déroulement de l'algo :
\rho[u] la plus courte distance provisoire de s à u
précédent(u) le sommet qui précède u sur le plus court chemin provisoire de s à u
Sconnu l'ensemble des sommets pour lesquels un plus court chemin depuis s est connu :
u ∈ Sconnu => $\phi[u] \in R+ et \rho[u] = \phi[u]$
Sinconnu son complémentaire S \ Sconnu

## Principe
### Au départ
Sconnu={s}, \rho[s]=0
Sinconnu = Sommets \ Sconnu
pour tout sommet u sucesseur de s sauf s:
    \rho[u] = poids(s,u)
    précédent(u) = s
pour tout sommet u différent de s qui n'est pas un successeur de s :
    \rho[u]=infini
    précédent(u) = None

### Principe
Tant que Sinconnu contient des sommets w tels que \rho[w) différent de l'inifini :
    parmi les sommets de Sinconnu,
    on choisit l'un des sommets u de distance provisoire \rho[u] la plus petite.
On met à jouer les distances provisoires des successeurs v de u tels que v \in Sconnu, en tenant compte de leur distance à u, c'est à dire de poids(u,v), qu'ils soient atteints ou non pour la première fois :
    Si un tel sommet v voit sa distance provisoire à s diminuée, c'est à dire lorsque \rho[u] + poids(u, v) < \rho[v], cela signifie que le chemin qui passe par u pour atteindre v est un raccourci par rapport au chemin de s à v précédemment enregistré.
    u devient alors le "précédent" de v et \rho[v] est diminuée :
        \rho[v] = \rho[u] + poids(u,v).

## L'algorithme
```txt
Algo PlusCourtChemin DIJKSTRA(Graphe, s):
    Début
        \rho[s]<-0
        Sconnu<-{s}
        Sinconnu<-Sommets \ {s}
        Pour chaque sommet u ∈ Sinconnu faire :
            \rho[u]<-infini
            précédent(u)<-None
        FinPour
        Pour chaque sommet u ∈ Successeurs(s)\{s} faire :
            \rho[u]<-poids(s,u)
            précédent(u)<-s
        FinPour
        {i} 1
        Tant que ∃ u ∈ Sinconnu tel que \rho[u] ≠infini :
            {i} 2
            Choisir u ∈ Sinconnu tel que \rho[u] soit minimal
            Pour chaque v ∈ Successeurs(u) ∩ Sinconnu faire:
                Si \rho[u] + poids(u,v) < \rho[v] faire:
                    \rho[v]<-\rho[u]+poids(u,v)
                    précédent(v)<-u
                FinSi
            FinPour
            Sconnu<-Sconnu ∪ {u}
            Sinconnu<-Sinconnu \ {u}
            {i} 3
        FinTantQue 
        {i} 4
    Fin
```

## La boucle termine
A chaque passage dans la boucle, Sinconnu perd un élément u tel que \rho[u] ≠infini.

## Preuve de l'algorithme

### Invariant

$\forall u \in Sconnu, \rho[u] = \phi[u]$

{i} 1 : prouvé
{i} 2 : prouvé
{i} 3 : Soit u ∈ Sinconnu tel que \rho[u] ∈ R+ soit minimal.
Prouvons que $\rho[u]$ = $\phi[u]$:
    (shéma)
    \rho[u] ≠infini donc il existe un chemin de s à u
    considérons ch un plus court chemin de s à u
    s ∈ Sconnu, u ∉ Sconnu et ch relie s à u
    Considérons y le premier sommet sur ch tel que y ∉ Sconnu et x son précédent sur ch ; x ∈ Sconnu
    ch se décompose ainsi: ch=ch1->ch2 où ch1 relie s à x en ne passant que par des sommets de Sconnu, et ch2 relie y à u.
    ch1 est sans arc lorsque s=x
    ch2 est sans arc lorsque y=u
    Prouvons que y=u ...
        y est un successeur de x et x ∈ Sconnu donc y a été traité dans la boucle au moment d'insérer x dans Sconnu et ainsi :
            \rho[x]=$\phi[x]$
            \rho[y]<=$\phi[x]+poids(x,y)$
        or $\phi[u]$ = longueur(ch)
            $\phi[u]$ = $\phi[x]$+poids(x,y)+longueur(ch2)
        mais $\phi[u]$<=\rho[u] et \rho[u]<=\rho[y]
        car \rho[u]=min(\rho[v], v ∈ Sinconnu)
        donc longueur(ch2)=0 et y=u!
    Nous venons de prouver : y=u donc u est sucesseur de x et x ∈ Sconnu
    ainsi : \rho[u]<=$\phi[x]$+poids(x,u)
    or ch est le plus court chemin de s à u
    donc $\phi[u]$ = longueur(ch) = $\phi[x]$ + poids(x,u)
    par suite : \rho[u]<=$\phi[x]$+poids(x,u)<=$\phi[u]$
    or $\phi[u]$<=\rho[u]
    finalement: \rho[u]=$\phi[u]$

    {i} 3 est prouvé.

{i} 4 : Prouvé
    En sortant de la boucle :
        $\forall u ∈ Sconnu, \rho[u]=$\phi[u]$
        et Sinconnu = $\emptyset$
        ou $\forall u ∈ Sinconnu, \rho[u]=infini
    Un plus court chemin depuis l'origine s vers tout autre sommet a été trouvé.
    En remontant la chaîne des "précédent", un tel chemin peut être reconstitué.
    La preuve est terminée.




