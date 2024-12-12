# Dijkstra

# L'exécution de Dijkstra

## Spécifiez le problème

Explicitez les préconditions et postconditions formellement (en respectant les notations mathématiques vues au cours).

### Problème de plus court chemin (PCC) (avec des distances positives)

Données soit :  
- Un graphe orienté G=(V,E)
- Une source s ∈ V
- Une fonction positive de pondération des arcs (w:E → ℝ^+) avec ( w(a,b)=10, w(b,c)=2, w(c,d)=9, w(d,e)=4, w(a,c)=5, w(b,d)=1, w(c,b)=3, w(c,e)=2, w(e,b)=2, w(e,d)=6 ).
- G=(V,E) et s=a

Problème : Trouver un plus court chemin de s vers tout autre sommet de G 

Distance/poids du chemin <a, c, b, d> : w(a,c)+w(c,b)+w(b,d)=5+3+1=9 

## Structure de données

### Quid des distances

Les tableaux de valeur phi vont être mis à jour au fil de l'algo et à la fin la distance optimale dans le tableau :

    Φ[i] : distance d’un pcc de s à i 

### Quid des chemins

    P[i] = j : j possède i dans un pcc de s à i 

Ce qui signifie que p de i vaut j si i est le prédecesseur immédiat dans le pcc que l’on a identifié entre s et i 

Si on possède le prédécesseur de chaque sommet, on peut reconstituer l’ensemble des pcc depuis s. 

## Grandes lignes de l'algo de Dijkstra

    φ[i]:distance d’un pcc de s à i 

    ρ[i]=j : j précède i dans un pcc de s à i 

### Algorithme de Dijkstra

(init) 
    ∀v∈V,φ[v]=+∞,ρ[v]=? 
    φ[s]=0 
    Soit Q un ensemble de sommets initialisé à V 
Tant que Q est non vide : 
    u ← un sommet de Q avec φ[u] minimum 
    Retirer u de Q 
    Pour tout v ∈ Γ⁺(u) : (v successeur de u, on explore les voisins de u) 
        [Par exemple, Γ⁺(b)={c,d}, Γ⁺(e)={b,d} ...] 
        si (φ[v]>φ[u]+w(u,v)) alors
            (màj)
                φ[v] = φ[u] + w(u,v)
                ρ[v] = u

| u   | Q                | Γ⁺(u)     | φ.ρ                              |
|     |                  |           | a    | b    | c    | d    | e    |
|-----|------------------|-----------|------|------|------|------|------|
| -   | {a, b, c, d, e}  | -         | 0, ? | +∞,? | +∞,? | +∞,? | +∞,? |
| a   | {b, c, d, e}     | {b, c}    | 0, ? | 10,a | 5,a  | +∞,? | +∞,? |
| c   | {b, d, e}        | {b, d, e} | 0, ? | 8,c  | 5,a  | 14,c | 7,c  |
| e   | {b, d}           | {b, d}    | 0, ? | 8,c  | 5,a  | 13,e | 7,c  |
| b   | {d}              | {c, d}    | 0, ? | 8,c  | 5,a  | 9,b  | 7,c  |
| d   | Ø                | {c}       | 0, ? | 8,c  | 5,a  | 9,b  | 7,c  |

L’état de φ et ρ la fin de la phase de l’initialisation, pair de valeur (+∞,?) 

On choisit un sommet dont la distance connue φ est minimum. Toutes les distances valent +∞ sauf pour la source a qui vaut 0. 

Le premier sommet que l’on va choisir, c’est la source, c’est le sommet a. En seconde ligne, on le retire de grand u. Ainsi l’ensemble W=V/Q va être l’ensemble de tous les sommets déjà traité. 

On va parcourir tous les voisins de u donc la source au début avec les voisins de a soit b et c. Pour chaque voisin, on regarde si on peut faire une mise à jour, si on a pas un meilleur chemin. 

Pour b, on ne connait pas de chemin, on a mis +∞ mais maintenant venant de a, on a le chemin φ[a] plus le poids de l’arc AB : w(a,b). Admettons, on dit que φ[a] vaut 0 et le poids de la distance de AB qui vaut 10 donc on a un chemin de distance 10, et on veut faire une mise à jour φ et ρ 

    φ[b]=+∞>φ[a]+w(a,b)=0+10=10 
    ⇒ φ[b]= φ[a]+ w(a,b)=10 
    ⇒ φ[b]=a 

Donc a (10,a) soit φ[b] qui vaut 10 et le prédécesseur de B vaut a. 

Idem pour c. 

    φ[c]=+∞>φ[a]+w(a,c)=0+5=5 
    ⇒ φ[c]= 5 
    ⇒ ρ[c]=a 

Donc φ[c] et ρ[c] sont meilleurs que l’on met à jour : (5,a) et toutes les autres valeurs restent inchangées : (+∞,?) pour d et e lorsque le sommet est a. 

Après ceci, nous avons fini la première itération de l'algorithme.

---

Et ainsi de suite, on prend à nouveau un sommet dans Q où φ est minimum lorsque Q vaut actuellement {b,c,d,e} c’est à dire c qui vaut 5 car a vaut 0, b vaut 10 et d et e qui valent +∞. 

On a finis la première itération de l’algorythme. 

On choisit le sommet c tel que φ  est le minimum dans Q dont le minimum dans Q entre 10, 5, plus l’infini et plus l’infini , hé bien c’est 5 donc le sommet choisi est le sommet c et on le retire de Q. 

On commence par examiner les voisins de C : B,D,E et pour chacun de ces voisins on va regarder si on ne trouve pas un meilleur chemin passant par C .

---

Vérifier si on trouve un meilleur chemin en passant par b : 

    φ[b]= 10 > φ[c]+w(c,b)=5+3=8 
    ⇒ φ[b]= 8 
    ⇒ ρ[b]=c 

On fait donc la mise à jour : (8,c) dans la colonne b pour le sommet c. 

Idem pour d et e, pour atteindre le sommet d (14,c) est mieux que +∞, et pour atteindre le sommet e (7,c) est mieux que +∞. 

---

On reprend les itérations suivantes, et ainsi parmi Q, quel est celui qui a le φ minimum, c’est e dont la distance φ vaut 7. On retire e de Q et on examine les voisins de e en commençant par b : 

    φ[b]= 8 > ? φ[e]+w(e,b)=7+2=9 

Et pour le cas de d : 

    φ[b]= 14 > φ[e]+w(e,d)=7+6=13 
    ⇒ φ[d]= 13 
    ⇒ ρ[d]=e 

Comme c’est meilleur que φ , on fait la mise à jour avec cette valeur de d (13,e) pour le prédécesseur de d qui était (14,c). 

Idem pour les deux dernier sommets pour lesquelles on marque la progression de l’algorithme. 

On retire le dernier sommet `Ø` sachant que d n’as qu’un seul voisin {c} et on peux vérifier la fin du déroulement de l’algorithme 

---

Maintenant que Q est vide, la condition de « Tant que » de l’agorithme n’est plus satisfaite donc l’algorithme le termine. 

On a la solution recherchée dans les valeurs de φ et ρ que l’on va représenter en prenant les sommet 1 à 1. 

Le sommet a est la source et il a une distance de 0 car c’était la source et il n’a pas de prédecesseur. 

Le sommet b a une distance optimale de 8 et l’algorithme nous dit que son prédecesseur c’est c donc on ajoute un arc c-b car le prédecesseur de b qui vaut c. 

Le sommet c a pour distance optimale 5 et on représente l’arc a-c car le prédecesseur de c c’est a. 

Pour d, distance 9 et l’arc b-d. 

Pour e, distance de 7 et l’arc c-e. 

On a donc la solution qui répond à notre problème et qui nous donnes tout les plus court chemin depuis a vers tout autre sommet de G. On retrouve bien le chemin le plus court entre A et D avec une distance 9, et le plus court chemin entre A et E avec une distance de 7. 

Et comme le plus court chemin est fait de plus court chemin, on a aussi le plus court chemin entre A et C et cetera. 

## Autre exemple : 
    - un graphe orienté G=(V,E) 
    - s=a 
    - Une fonction positive de pondération des arcs (w:E → ℝ^+) avec ( w(b,a)=1, w(a,c)=4, w(a,d)=10, w(a,e)=9, w(c,b)=2, w(b,e)=1, w(d,c)=2, w(e,c)=1, w(c,e)=4, w(d,e)=6, w(e,d)=2). 
    - G=(V,E) et s=a 

Tableau pour suivre l’exécution pas à pas. 

| u   | Q                | Γ⁺(u)     | φ.ρ                              |
|     |                  |           | a    | b    | c    | d    | e    |
|-----|------------------|-----------|------|------|------|------|------|
| -   | {a, b, c, d, e}  | -         | 0, ? | +∞,? | +∞,? | +∞,? | +∞,? |
| a   | {b, c, d, e}     | {c, d, e} | 0, ? | +∞,? | 4,a  | 10,a | 9,a  |
| c   | {b, d, e}        | {e, b}    | 0, ? | 6,c  | 4,a  | 10,a | 8,c  |
| e   | {b, d}           | {a, e}    | 0, ? | 6,c  | 4,a  | 10,a | 7,b  |
| b   | {d}              | {d, c}    | 0, ? | 6,c  | 4,a  | 9,e  | 7,b  |
| d   | Ø                | {e, c}    | 0, ? | 6,c  | 4,a  | 9,e  | 7,b  |

## Preuve d’optimalité

Pourquoi l’agorithme de Dijkstra calcul bien le plus court chemin ? 

L’ensemble W=V\Q est l’ensemble des sommets déjà traité à chaque itération. W est le complémentaire de Q dans V. A la fin de l’algorithme, Q est vide et W vaut l’ensemble de tous les sommets et obtiens l’arborescence des plus court chemins. 

La signification de W qui progresse à chaque itération. 

## Teminaison 

La terminaison est assez clair car on a commencé avec un Q initialisé à tous les sommets du graphe. 

n sommets dans le graphe, vaut n sommets dans Q, et à chaque itération, on en retire un tant que Q est non vide. 

## Optimalité

Optimalité : 
    À la fin de l’algorithme, pour tout x ∊ V 
    φ[x] : plus petite distance pour aller de s à x 

### Prouvons par récurence : 

> (P) :
    À chaque itération, pour tout x ∊ V
    φ[x] : plus petite distance pour aller de s à x utilisant **seulement les sommets de W comme intermédiaires (vrai à chaque itération)**

Cette propriété noté P, vrai à chaque itération. 

Ici je me place à la fin de la 1e itération après avoir ajouté la source et avoir fait la mise à jour pour la source et je veux simplement vérifier que P est vrai à la fin de la 1e itération. 

+ Pour W = {s} : φ[y] = w{s,y} ∀y∈Γ⁺(s) 

Alors dans cette situation, on a mis à jour φ pour tous les Y qui sont voisins de S et on a mis dans φ[y] la valeur de la distance de l’arc w(s,y) donc pour ces voisins là P est bien vérifié puisqu’on a bien les valeurs des plus court chemins utilisant uniquement S comme intermédiaire c’est l’arc direct pour faire s,y “φ[y] = w{s,y}” et puis tous les sommets qui ne sont pas des voisins de s, on ne peux pas les atteindre uniquement avec s, il faut utiliser d’autres sommets donc la valeur Z est réstée à l’infini “φ[z] = +∞” indique qu’il n’existe pas de chemin permettant de les atteindre uniquement avec S en l’occurence ici donc P est bien vérifié à la fin de la première itération donc maintenant on va supposer qu’on a P valide à une certaine itération et on va exécuter l’itération suivante en essayant de vérifier pas à pas que P reste vrai. 

    s-> φ[y] = w{s,y} 
    s -> φ[z] = +∞ 

Alors la 1e étape, on considère un sommet tel que φ[u] est minimum 

+ On considère u tel que φ[u] est minimum. 

> (a) : Un pcc de s à u n’utilise que des sommets de W 

Ce qui est vrai car si ce n’était pas le cas, on aurait un chemin qui passe par un sommet y n’appartenant pas à W donc à grand Q, et ce ne serait pas possible d’avoir un chemin plus court car φ[y] est plus grand que φ[u] tel que φ[u] est minimum. φ[y] est plus grand que φ[u] et que les distances sont positives. 

Si "Un pcc de s à u n’utilise que des sommets de W" n’était pas le cas alors φ[u] ne serait pas minimum car w(y,u)>0 

Ainsi toutes les distances sont considérée positive alors ça c’est une hypothèse de notre algorithme de Dijkstra. 

+ On ajoute u à W et on fait la mise à jour :

    φ[v] = min(φ[v], φ[u] + w{s,v}) ∀v∈Γ⁺(u) 

note : pour tous les voisins de u, on a potentiellement pê trouvé un chemin plus court. 

    => vérifions (P) pour un v 

    (1) φ[v] est inchangée après la mise à jour => (P) est vérifié par hypothèse de récurrence. 

    (2) Un chemin plus court passe par u =>(P) est vérifié par (a) 

    rappel : (a) Un pcc de s à u n’utilise que des sommets de W 

+ À la fin W=V et (P) établit l’optimalité de Dijkstra. 

### Restriction aux distances positives 

Poids négatifs = contre exemple 
w(s,b)=2,w(s,c)=3,w(c,b)=-2
Si on exécute Dijkstra, on va trouver une distance pour atteindre B valant 2 alors que le plus court chemin de S à B 1 car 3-2.
C'est en effet cette propriété (a) qui n'est pas vrai lorsqu'on a une distance négative.

Exécution de Dijkstra mais le pcc de s à b vaut 1.

Voilà pour la preuve de l'optimalité de Dijkstra.

                    Dijkstra        Bellman-Ford
Poids négatifs      NON             OUI
Compléxité          O(n2+m)         O(n,m)
                    O(nlog(n)+m)    
Circuit négatifs    NON             NON

* Circuit négatifs/absorbants. La valeur du pcc de s à e n'est pas définie.

## Compléxité

Algorithme de Dijkstra : |V|=n|E|=m
(init) 
    ∀v∈V,φ[v]=+∞,ρ[v]=? 
    φ[s]=0 
    Soit Q un ensemble de sommets initialisé à V 
Tant que Q est non vide : 
    u ← un sommet de Q avec φ[u] minimum 
    Retirer u de Q 
    Pour tout v ∈ Γ⁺(u) : (v successeur de u) 
        si (φ[v]>φ[u]+w(u,v)) alors
            (màj)
                φ[v] = φ[u] + w(u,v)
                ρ[v] = u

begin
    S=0; S̄=V
    d(i)=∞ ∀i∈V
    d(s)=0, pred(s)=0
    while |S| < n, do
        begin
            let i = arg min {d(j) : j ∈ S̄}
            S = S ∪ {i}
            S̄ = S̄ \ {i}
            for each j ∈ V⁺(i) , do
                if d(j) > d(i) + δ(i,j)
                    d(j) = d(i) + δ(i,j)
                    pred(j) = i
                end
            end
        end
    end
end

Pseudo-code de l'algorithme de Dijkstra [Blondel, 2014]

Entrées :
G = (S, A) un graphe avec une pondération positive des arcs,
poids des arcs,
s_deb un sommet de S

P := ∅
d[a] := +∞ pour chaque sommet a
d[s_deb] = 0

Tant qu'il existe un sommet hors de P
    Choisir un sommet a hors de P de plus petite distance d[a]
    Mettre a dans P
    Pour chaque sommet b hors de P voisin de a
       Si d[b] > d[a] + poids(a, b)
           d[b] = d[a] + poids(a, b)
           prédécesseur[b] := a
    Fin Pour
Fin Tant Que

source : https://fr.wikipedia.org/wiki/Algorithme_de_Dijkstra


## Sources

https://www.youtube.com/watch?v=YEjUnoca6zs&t=102s
https://fr.wikipedia.org/wiki/Table_des_symboles_litt%C3%A9raux_en_math%C3%A9matiques 

https://www.youtube.com/watch?v=85r5OTsl3Fk&list=PLjWBg-aa2xpLsXRPCDSnhutX0BP9Th-DB 
https://fr.wikipedia.org/wiki/Table_des_symboles_litt%C3%A9raux_en_math%C3%A9matiques 