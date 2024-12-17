https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

# Algorythme Dijkstra

> A.1 Algorithme de Dijkstra : L'algorithme de Dijkstra est utile pour trouver le chemin le moins coûteux entre deux nœuds d’un graphe pondéré. Il nécessite l'utilisation d'une structure de données efficace comme une file de priorité (souvent implémentée avec un tas). Il est important de prouver que les nœuds déjà visités ont leur plus court chemin correctement calculé.

## 1. Effectuez des recherches pour comprendre l'algorithme choisi en profondeur. Vous devrez utiliser des ressources académiques ou en ligne pour mieux comprendre son fonctionnement et les théories qui le sous-tendent. Listez vos sources, expliquez en quelques mots pourquoi vous avez le choix de cet algorithme en particulier, et donnez son contexte d’utilisation (dans quels cas concrets est-il typiquement utilisé ?). 

+ Choix de l'algorithme : Dijkstra's algorithm,
    - Algorithme de Dijkstra : Trouve le chemin le plus court dans un graphe pondéré (arêtes avec poids) à partir d'un sommet source vers tous les autres sommets (Single-source shortest path). Utilise les concepts de sommets, arêtes, poids, et chemins.
    - Graph theory : G = (V, E) : Sommets (V) et Arêtes (E) connectés.
        Graphe (G) : Ensemble de sommets (V) et arêtes (E).
        Sommets (V) : Points ou nœuds du graphe.
        Arêtes (E) : Liens entre les sommets.
        Graphe simple : Pas de boucles ni d'arêtes multiples.
        Boucle : Arête reliant un sommet à lui-même.
        Multigraphe : Contient des boucles et/ou des arêtes multiples.
        Graphe complet (Kn) : Toutes les arêtes possibles entre n sommets.
        Parcours (P) : Séquence de sommets et d'arêtes.
        Chemin : Parcours sans répétition de sommets.
        Circuit : Parcours fermé revenant au sommet initial.
        Acyclique : Pas de circuits.
        Connexe : Chemin entre chaque paire de sommets.
        Composantes connexes : Sous-graphes connexes.
        Graphe orienté (Digraphe) : Arêtes avec direction (queue vers tête).
        Matrice adjacente : Représentation matricielle des connexions.
    - Greedy algorithm : choix de la meilleure option à chaque itération (https://www.geeksforgeeks.org/greedy-algorithms/).
    - Weighted graphs
    - Priority queue
    - Heap data structure

+ Contexte d'utilisation

- **Routes fiscales** : optimiser les routes fiscales des multinationales (Delhaye, V., 2015).
- **Navigation GPS** : trouver le chemin le plus court.
- **Réseaux de télécommunications** : minimiser les délais de transmission (ex : OSPF, Open Shortest Path First).
- **Gestion du trafic** : éviter les embouteillages.

+ Cas concrets


### Sources
https://webcampus.unamur.be/pluginfile.php/50153/mod_resource/content/2/2019-2020.pdf
https://www.geeksforgeeks.org/binary-heap/
https://www.geeksforgeeks.org/heap-data-structure/
https://www.geeksforgeeks.org/dijkstras-algorithm-for-adjacency-list-representation-greedy-algo-8/
https://d-michail.github.io/assets/teaching/data-structures/033_BinaryHeapImplementation.en.pdf

[Blondel, 2014] Blondel, V. (2014). Mathématiques discrètes 1 : Théorie et algorithmique des graphes. Technical report, UCL/EPL. Cours LINMA1691.

https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
https://www.geeksforgeeks.org/introduction-to-dijkstras-shortest-path-algorithm/?ref=header_outind
https://www.geeksforgeeks.org/greedy-algorithms/
https://ils.bib.uclouvain.be/unamur
https://www.unamur.be/fr/bump/bookalibrarian
https://fr.piliapp.com/symbol/math/


Szczesniak, I., & Woźna-Szcześniak, B. (n.d.). *Generic Dijkstra: correctness and tractability*. Czestochowa University of Technology, Department of Computer Science & Jan Długosz University in Czestochowa, Department of Mathematics and Computer Science. Retrieved from [arXiv](https://arxiv.org/pdf/2204.13547).

Delhaye, V. (2015). *Le plus court chemin d’imposition des multinationales : application de l’algorithme de Dijkstra*. UCLouvain, Louvain School of Management. Retrieved from UCLouvain.


Livres "Introduction to Algorithms" de Cormen (chapitres sur les graphes). => https://ils.bib.uclouvain.be/unamur/documents/1471273

https://graphviz.org/docs/library/


Champagne, J. (2023). Langage C #22 - Graphes. YouTube. https://www.youtube.com/watch?v=T5MU8NDMMj4 
Champagne, J. (2024). Architecture - graphe. YouTube. https://www.youtube.com/watch?v=TwO8rCTFy1c

https://fr.wikipedia.org/wiki/Algorithme_de_Dijkstra
https://fr.wikipedia.org/wiki/Liste_d%27adjacence
https://fr.wikipedia.org/wiki/Matrice_d%27adjacence
https://fr.wikipedia.org/wiki/Liste_d%27adjacence
https://lacl.u-pec.fr/dima/complexite/cours4.pdf

https://perso.eleves.ens-rennes.fr/people/Julie.Parreaux/fichiers_agreg/info_dev/Dijkstra.pdf
[1] Rivest R. Stein C. Cormen T., Leiserson C. Algorithmique, 3ème édition. Dunod, 2010

http://yallouz.arie.free.fr/terminale_cours/2017-2018/tes-2017-2018-dijkstra.pdf

https://pcsi1-saint-louis.ovh/site/images/Doc2223/ch22_Dijkstra.pdf

http://dominique.frin.free.fr/terminales/exosTES-Dijkstra-cor.pdf

https://www.normalesup.org/~dconduche/informatique/PT/Cours/Dijkstra.pdf

https://www.youtube.com/watch?v=YEjUnoca6zs&t=102s
https://fr.wikipedia.org/wiki/Table_des_symboles_litt%C3%A9raux_en_math%C3%A9matiques 

https://www.youtube.com/watch?v=85r5OTsl3Fk&list=PLjWBg-aa2xpLsXRPCDSnhutX0BP9Th-DB 
https://fr.wikipedia.org/wiki/Table_des_symboles_litt%C3%A9raux_en_math%C3%A9matiques 

# Spécification

> 2. Spécifiez le problème : explicitez les préconditions et postconditions formellement (en respectant les notations mathématiques vues au cours).

## environnement
```c
int V, E, src;
Graph* graph; // Représentation du graphe sous forme de liste d'adjacence
int dist[V]; // Tableau des distances
int pred[V]; // Tableau des prédécesseurs
```

Soit ( G = (V, E) ) un graphe où ( V ) est l'ensemble des sommets ((|V| = V₀)) et ( E \subseteq V \times V ) l'ensemble des arêtes pondérées par une fonction ( w : E \to \mathbb{R}^+ ).

## Précondition (formalisée mathématiquement)

<br>

$$
\begin{aligned}
\text{pré} \equiv & \\
    & V = V₀ > 0 \land E = E₀ \geq 0 \land \text{src} = \text{src₀ } \land \\
    & \forall (u, v) \in E₀ : w(u, v) \geq 0
\end{aligned}
$$

$V_0$ est le nombre de sommets ($V_0 > 0$).  
$E_0$ est le nombre d'arêtes ($E_0 \geq 0$).  
$\text{src}_0$ est le sommet source, $\text{src} \in [0, V-1]$.  
Les poids des arêtes $w(u, v)$ sont non négatifs ($w(u, v) \geq 0$).  
Cette formulation se base uniquement sur les arêtes existantes dans $E_0$, ce qui correspond à l'utilisation d'une liste d'adjacence comme structure de données.


> **Remarque** : Je choisis la liste d'adjacence car la matrice d'adjacence :
$$ V₀ > 0 \land \forall i,j : 0 \leq i,j < V₀ : \text{graph}[i][j] \geq 0$$

> nécessite $O(V₀^2)$ d’espace. Cela est dû au fait que `graph[i][j]` représente le poids de l’arête entre `i` et `j`, ou ∞ si l’arête est absente, ce qui permet un accès direct mais utilise beaucoup d'espace. En revanche, la liste d'adjacence :
$$V₀ > 0 \land \forall (u,v) \in E₀ : w(u,v) \geq 0$$

> utilise $O(V₀ + |E₀|)$ d’espace, ce qui est optimal pour les graphes creux (sparse) car seules les arêtes existantes sont stockées.

## Orientation du graphe

Dans mon implémentation, je travaille avec des graphes orientés ou non orientés. Un graphe orienté signifie que les arêtes ont une direction, tandis qu'un graphe non orienté n'a pas de direction spécifique pour ses arêtes. Cela se reflète dans les structures de données et les préconditions utilisées dans le code.

### Graphe orienté

Un graphe orienté est défini comme suit :

$$G = (V, E)$$

où :
- $V$ est l'ensemble des sommets.
- $E \subseteq V \times V$ est l'ensemble des arêtes orientées.

Pour un graphe orienté, une arête $(v_1, v_2) \in E$ n'implique pas nécessairement que $(v_2, v_1) \in E$. Cela signifie que l'arête $(v_1, v_2)$ existe, mais l'arête inverse $(v_2, v_1)$ n'existe pas nécessairement.

### Graphe non orienté

Un graphe non orienté est défini comme suit :

$$G = (V, E)$$

où :
- $V$ est l'ensemble des sommets.
- $E \subseteq \{ \{v_1, v_2\} \mid v_1, v_2 \in V \}$ est l'ensemble des arêtes non orientées.

Pour un graphe non orienté, une arête $\{v_1, v_2\} \in E$ implique que $\{v_2, v_1\} \in E$. Cela signifie que l'arête entre $v_1$ et $v_2$ n'a pas de direction spécifique.

### Implémentation en C

Dans le code, la création d'un graphe orienté ou non orienté est déterminée par un booléen `is_oriented` :

```c
Graph* g = new_graph(NUM_VERTICES, true); // Graphe orienté
Graph* g = new_graph(NUM_VERTICES, false); // Graphe non orienté
```

Lors de l'ajout d'une arête, le code vérifie si le graphe est orienté ou non pour décider d'ajouter l'arête dans les deux sens ou non :

```c
void add_edge(Graph *g, int src, int dest, int weight) {
    NodeList* newNode = add_node(dest, weight);
    newNode->next = g->tab_neighbours[src].head;
    g->tab_neighbours[src].head = newNode;

    if (!g->is_oriented) {
        newNode = add_node(src, weight);
        newNode->next = g->tab_neighbours[dest].head;
        g->tab_neighbours[dest].head = newNode;
    }
}
```

Cette distinction permet de gérer les graphes orientés et non orientés de manière flexible et efficace.

## Postcondition (formalisée mathématiquement)

<br>

$$
\text{post} \equiv \forall v \in V : \text{dist}[v] = 
\begin{cases} 
\min\left(\sum\limits_{(u,v) \in P} w(u,v)\right) & \text{si } P \text{ existe} \\ 
\infty & \text{sinon}
\end{cases}
$$

Pour chaque sommet $v$, $\text{dist}[v]$ contient la distance minimale depuis le sommet source $\text{src}$ jusqu'à $v$. Si un chemin $P$ existe de $\text{src}$ à $v$, alors $\text{dist}[v]$ contient la somme minimale des poids des arêtes de $P$. Si aucun chemin n'existe, $\text{dist}[v] = \infty$.

### Vérification dans le code
La distance initiale des sommets est définie comme $\infty$ : `dist[i] = INT_MAX`.  
La distance est mise à jour uniquement si un chemin existe, via la condition :
```c
if (!sptSet[v] && dist[u] != INT_MAX && tmp->weight + dist[u] < dist[v]) {
    dist[v] = dist[u] + tmp->weight;
}
```
Les sommets inatteignables depuis la source ne sont jamais mis à jour, donc $\text{dist}[v]$ reste $\infty$.

Lorsque j'utilisais une matrice d'adjacence, ma post-condition était :

<br>

$$
\text{post} \equiv \forall v (0 \leq v < V_0) : \text{dist}[v] = \min\left(\sum_{(u,w) \in P} \text{graph}[u][w]\right) \text{ où } P \text{ est un chemin de } \text{src}_0 \text{ à } v
$$

Il est important de rappeler que pour chaque sommet $v$, $\text{dist}[v]$ contient la distance minimale depuis le sommet source $\text{src}_0$ jusqu'à $v$, mais en relation avec les listes d'adjacence.


## Invariant de boucle (infos)
Pendant l'exécution de l'algorithme, après chaque itération $k$, l'invariant suivant est satisfait :

+ Invariant de validité :
Pour chaque sommet $u$ dans l'ensemble $S_k$ (les sommets pour lesquels la distance minimale a été confirmée après $k$ itérations), $\text{dist}[u]$ est la distance minimale depuis la source $\text{src}$ jusqu'à $u$.

$$
\forall u \in S_k : \text{dist}[u] = \min(\text{dist}(\text{src}, u))
$$

+ Invariant sur les distances :
Pour chaque sommet $v$ qui n'est pas dans $S_k$ (les sommets qui n'ont pas encore été traités), $\text{dist}[v]$ est une estimation de la distance minimale depuis la source $\text{src}$ jusqu'à $v$.

$$
\forall v \notin S_k : \text{dist}[v] \geq \min(\text{dist}(\text{src}, v))
$$

+ Invariant de mise à jour :
Pour chaque arête $(u, v)$ dans le graphe, si $u$ est dans $S_k$ et $v$ ne l'est pas, alors $\text{dist}[v]$ est au moins $\text{dist}[u]$ plus le poids de l'arête $(u, v)$.

$$
\forall (u, v) \in E : \text{dist}[v] \leq \text{dist}[u] + w(u, v)
$$

+ Commentaires sur votre algorithme : Les trois propriétés mentionnées ci-dessus garantissent que l'algorithme converge correctement. Ces invariants sont maintenus grâce à l'exploration systématique des sommets adjacents et la mise à jour des distances via les conditions sur $\text{sptSet}[v]$ et $\text{dist}[v]$.

```c
if (!sptSet[v] && dist[u] != INT_MAX && tmp->weight + dist[u] < dist[v]) {
    dist[v] = dist[u] + tmp->weight;
}
```

Convergence : À la fin de l'algorithme, $S_k$ contient tous les sommets atteignables depuis $\text{src}$, et $\text{dist}[v]$ est valide pour tous les sommets $v$.

```c
// boucles du code
```


# Implémentation

> Implémentez l'algorithme en C. Vous êtes autorisés à vous aider des ressources que vous trouvez, mais l’implémentation doit être votre propre travail : vous devez vous l’approprier et en maîtriser tous les détails. Dans le rapport, vous donnerez le code (commenté) de votre implémentation, vous détaillerez les structures de données utilisées et expliquer pourquoi elles sont adaptées à l'algorithme choisi.

```c
#include "dijkstra.h"

/**
 * Algorithme de Dijkstra sans Min-Heap.
 * @param graph Graph sous forme de liste d'adjacence.
 * @param src Sommet source pour les plus courts chemins.
 */
void dijkstra_simple(Graph *graph, int src) {
    int V = graph->nb_vertices;
    int dist[V]; // φ[v]
    int pred[V]; // ρ[v]
    Boolean sptSet[V]; // Q

    // Initialiser toutes les distances comme infinies et sptSet[] comme faux
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX; // φ[v]=+∞
        sptSet[i] = false; // Q
        pred[i] = -1; // ρ[v]=?
    }

    // La distance du sommet source à lui-même est toujours 0
    dist[src] = 0; // φ[s]=0

    // Trouver le chemin le plus court pour tous les sommets
    for (int count = 0; count < V - 1; count++) {
        // Choisir le sommet de distance minimale parmi ceux qui ne sont pas encore traités
        int u = -1; // u ← un sommet de Q avec φ[u] minimum
        int min_dist = INT_MAX; // Initialiser à la valeur maximale
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && dist[v] <= min_dist) {
                min_dist = dist[v]; // màj min_dist
                u = v; // màj le sommet avec la distance minimale
            }
        }

        if(u == -1) break; // Si aucun sommet n'a été trouvé, sortir de la boucle
        sptSet[u] = true; // Retirer u de Q

        // Pointeur temporaire pour parcourir la liste d'adjacence des sommets adjacents au sommet choisi.
        NodeList* tmp = graph->tab_neighbours[u].head;
        while (tmp != NULL) {
            int v = tmp->dest; // Pour tout v ∈ Γ⁺(u)
            if (!sptSet[v] && dist[u] != INT_MAX && tmp->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + tmp->weight; // φ[v] = φ[u] + w(u,v)
                pred[v] = u; // ρ[v] = u
            }
            tmp = tmp->next;
        }
    }

    // Afficher les distances finales et les prédécesseurs
    print_shortest_paths(graph, dist, pred);

    // Afficher les distances
    print_arr(dist, V);
}
```
- $V$ : Nombre total de sommets.
- $E$ : Nombre total d'arêtes.
- $\text{src}$ : Sommet source pour Dijkstra.
- $\text{graph}$ : Représentation du graphe en liste d'adjacence.
- $\text{dist}$ : Tableau des distances minimales.
- $\text{pred}$ : Tableau des prédécesseurs des sommets.
- $\text{sptSet}$ : Ensemble des sommets traités (Shortest Path Tree Set).
- $\text{NodeList}$ : Liste des voisins d'un sommet.

### Exemple 1 :
Considérons le graphe suivant :

```
    (0)
   / | \
  1  4  2
 /   |   \
(1)  3   (2)
```

Avec les poids des arêtes :

$(0, 1) = 1$  
$(0, 2) = 2$  
$(0, 3) = 4$  
$(1, 3) = 3$  
$(2, 3) = 2$  

Si $\text{src} = 0$, alors les distances minimales calculées par l'algorithme de Dijkstra sont :

$\text{dist}[0] = 0$  
$\text{dist}[1] = 1$  
$\text{dist}[2] = 2$  
$\text{dist}[3] = 4$  

### Exemple 2 :

Considérons un autre graphe :

```
    (0)
   /   \
  1     4
 / \   / \
(1) 2 (2) 3
```

Avec les poids des arêtes :

$(0, 1) = 1$  
$(0, 2) = 4$  
$(1, 2) = 2$  
$(1, 3) = 5$  
$(2, 3) = 1$  

Si $\text{src} = 0$, alors les distances minimales calculées par l'algorithme de Dijkstra sont :

$\text{dist}[0] = 0$  
$\text{dist}[1] = 1$  
$\text{dist}[2] = 3$  
$\text{dist}[3] = 4$  

## 4. En vos propres mots, expliquez comment fonctionne l'algorithme. Décrivez de manière intuitive pourquoi l’implémentation produit un résultat correct par rapport à vos spécifications.

L'algorithme de Dijkstra permet de trouver les plus courts chemins depuis un sommet source $\text{src}$ vers tous les autres sommets d'un graphe $G = (V, E)$, à condition que les poids des arêtes soient non négatifs ($w(u, v) \geq 0 \, \forall (u, v) \in E$).

Données soit :  
- Un graphe orienté G=(V,E)
- Une source s ∈ V
- Une fonction positive de pondération des arcs (w:E → ℝ^+) avec ( w(a,b)=10, w(b,c)=2, w(c,d)=9, w(d,e)=4, w(a,c)=5, w(b,d)=1, w(c,b)=3, w(c,e)=2, w(e,b)=2, w(e,d)=6 ).
- G=(V,E) et s=a

Problème : Trouver un plus court chemin de s vers tout autre sommet de G

1. Initiatlisation

L'algorithme initialise $\phi[v] = +\infty$ pour tous les sommets $v$, sauf pour la source $\text{src}$, où $\phi[\text{src}] = 0$. Les prédécesseurs $\rho[v]$ sont initialisés à une valeur indéfinie ($?$). Un ensemble $Q$ contient tous les sommets non encore traités.
```c
∀v∈V, φ[v]=+∞, ρ[v]=? 
φ[src]=0 
Q = {a, b, c, d, e}
```
<table> <tr> <th>u</th><th>Q</th><th>Γ⁺(u)</th><th>a</th><th>b</th><th>c</th><th>d</th><th>e</th> </tr> <tr> <td>-</td><td>{a, b, c, d, e}</td><td>-</td><td>0, ?</td><td>+∞, ?</td><td>+∞, ?</td><td>+∞, ?</td><td>+∞, ?</td> </tr> </table>

> À chaque itération, le sommet $u$ avec la plus petite distance $\phi[u]$ dans $Q$ est sélectionné (garantissant que $\phi[u]$ est optimal).  
> Ce sommet $u$ est retiré de $Q$ et marqué comme "traité".  
> Les voisins $v$ de $u$ sont explorés pour mettre à jour leur distance estimée $\phi[v]$, selon la formule :  
> $\phi[v] = \min(\phi[v], \phi[u] + w(u, v))$  
> Si une mise à jour est effectuée, le prédécesseur $\rho[v]$ est mis à jour : $\rho[v] = u$.

2. Première itération ($u = a$)  
Le sommet $u = a$ est sélectionné car $\phi[a] = 0$ (le minimum dans $Q$).  
On explore ses voisins $\Gamma^+(a) = \{b, c\}$.

Mise à jour pour $b$ :

$\phi[b] = \min(\phi[b], \phi[a] + w(a, b)) = \min(+\infty, 0 + 10) = 10$  
$\rho[b] = a$

Mise à jour pour $c$ :

$\phi[c] = \min(\phi[c], \phi[a] + w(a, c)) = \min(+\infty, 0 + 5) = 5$  
$\rho[c] = a$

Nouvel état des tableaux :

<table> <tr> <th>u</th><th>Q</th><th>Γ⁺(u)</th><th>a</th><th>b</th><th>c</th><th>d</th><th>e</th> </tr> <tr> <td>a</td><td>{b, c, d, e}</td><td>{b, c}</td><td>0, ?</td><td>10, a</td><td>5, a</td><td>+∞, ?</td><td>+∞, ?</td> </tr> </table>

3. Deuxième itération ($u = c$)  
Le sommet $u = c$ est sélectionné car $\phi[c] = 5$ (le minimum dans $Q$).  
On explore ses voisins $\Gamma^+(c) = \{b, d, e\}$.

Mise à jour pour $b$ :

$\phi[b] = \min(\phi[b], \phi[c] + w(c, b)) = \min(10, 5 + 3) = 8$  
$\rho[b] = c$

Mise à jour pour $d$ :

$\phi[d] = \min(\phi[d], \phi[c] + w(c, d)) = \min(+\infty, 5 + 9) = 14$  
$\rho[d] = c$

Mise à jour pour $e$ :

$\phi[e] = \min(\phi[e], \phi[c] + w(c, e)) = \min(+\infty, 5 + 2) = 7$  
$\rho[e] = c$

Nouvel état des tableaux :

<table> <tr> <th>u</th><th>Q</th><th>Γ⁺(u)</th><th>a</th><th>b</th><th>c</th><th>d</th><th>e</th> </tr> <tr> <td>c</td><td>{b, d, e}</td><td>{b, d, e}</td><td>0, ?</td><td>8, c</td><td>5, a</td><td>14, c</td><td>7, c</td> </tr> </table>

4. Troisième itération ($u = e$)  
Le sommet $u = e$ est sélectionné car $\phi[e] = 7$.  
On explore ses voisins $\Gamma^+(e) = \{b, d\}$.

Mise à jour pour $d$ :

$\phi[d] = \min(\phi[d], \phi[e] + w(e, d)) = \min(14, 7 + 6) = 13$  
$\rho[d] = e$

Nouvel état des tableaux :

<table> <tr> <th>u</th><th>Q</th><th>Γ⁺(u)</th><th>a</th><th>b</th><th>c</th><th>d</th><th>e</th> </tr> <tr> <td>e</td><td>{b, d}</td><td>{b, d}</td><td>0, ?</td><td>8, c</td><td>5, a</td><td>13, e</td><td>7, c</td> </tr> </table>

5. Quatrième itération ($u = b$)  
Le sommet $u = b$ est sélectionné car $\phi[b] = 8$.  
On explore ses voisins $\Gamma^+(b) = \{d\}$.

Mise à jour pour $d$ :

$\phi[d] = \min(\phi[d], \phi[b] + w(b, d)) = \min(13, 8 + 1) = 9$  
$\rho[d] = b$

Nouvel état des tableaux :

<table> <tr> <th>u</th><th>Q</th><th>Γ⁺(u)</th><th>a</th><th>b</th><th>c</th><th>d</th><th>e</th> </tr> <tr> <td>b</td><td>{d}</td><td>{d}</td><td>0, ?</td><td>8, c</td><td>5, a</td><td>9, b</td><td>7, c</td> </tr> </table>

6. Cinquième itération ($u = d$)  
Le sommet $u = d$ est sélectionné car $\phi[d] = 9$.  
Comme $d$ n’a pas de voisins non traités ($\Gamma^+(d) = \emptyset$), aucune mise à jour n'est effectuée.

7. Terminaison

> L'algorithme s'arrête lorsque $Q$ est vide, c'est-à-dire que tous les sommets atteignables ont été traités.

L’ensemble $Q$ est désormais vide. Les valeurs finales de $\phi$ et $\rho$ représentent les distances minimales et les prédécesseurs pour les plus courts chemins depuis $a$.

<table> <tr> <th>u</th><th>Q</th><th>Γ⁺(u)</th><th colspan="5">φ.ρ</th> </tr> <tr> <td></td><td></td><td></td><td>a</td><td>b</td><td>c</td><td>d</td><td>e</td> </tr> <tr> <td>-</td><td>{a, b, c, d, e}</td><td>-</td><td>0, ?</td><td>+∞, ?</td><td>+∞, ?</td><td>+∞, ?</td><td>+∞, ?</td> </tr> <tr> <td>a</td><td>{b, c, d, e}</td><td>{b, c}</td><td>0, ?</td><td>10, a</td><td>5, a</td><td>+∞, ?</td><td>+∞, ?</td> </tr> <tr> <td>c</td><td>{b, d, e}</td><td>{b, d, e}</td><td>0, ?</td><td>8, c</td><td>5, a</td><td>14, c</td><td>7, c</td> </tr> <tr> <td>e</td><td>{b, d}</td><td>{b, d}</td><td>0, ?</td><td>8, c</td><td>5, a</td><td>13, e</td><td>7, c</td> </tr> <tr> <td>b</td><td>{d}</td><td>{c, d}</td><td>0, ?</td><td>8, c</td><td>5, a</td><td>9, b</td><td>7, c</td> </tr> <tr> <td>d</td><td>Ø</td><td>{c}</td><td>0, ?</td><td>8, c</td><td>5, a</td><td>9, b</td><td>7, c</td> </tr> </table>

8. Résultat final :

> $\phi[v]$ contient la distance minimale de $\text{src}$ à $v$.  
> $\rho[v]$ permet de reconstituer les chemins minimaux.

Distances minimales ($\phi$) :  
$\phi[a] = 0$,  
$\phi[b] = 8$,  
$\phi[c] = 5$,  
$\phi[d] = 9$,  
$\phi[e] = 7$.  

Chemins :

$b \leftarrow c \leftarrow a$  
$c \leftarrow a$  
$d \leftarrow b \leftarrow c \leftarrow a$  
$e \leftarrow c \leftarrow a$  

## 5. Identifiez un invariant de boucle pertinent pour l'algorithme. Formulez cet invariant et démontrez, de manière formelle, qu'il est vérifié à chaque itération de la boucle concernée. Expliquez en quoi il permettrait, dans une preuve de programme plus complète, de faire le pont entre pré- et post- conditions.

L’invariant de boucle pour l’algorithme de Dijkstra s’écrit comme suit :

$$I \equiv \forall v \in V : \begin{cases} 
\text{dist}[v] = \min_{P \in P_{\text{src}, v}} \sum_{e \in P} w(e) & \text{si } v \in S, \\
\text{dist}[v] \geq \min_{P \in P_{\text{src}, v}} \sum_{e \in P} w(e) & \text{si } v \notin S.
\end{cases}$$

Explications :

$S$ est l'ensemble des sommets pour lesquels la distance minimale a été confirmée (traités : $\text{sptSet}[u] = \text{true}$).  
$V \setminus S$ est l'ensemble des sommets non encore traités.  
$P_{\text{src}, v}$ est l'ensemble des chemins de la source $\text{src}$ au sommet $v$.  
$\sum_{e \in P} w(e)$ est la somme des poids des arêtes appartenant au chemin $P$.

## 6. Analysez la complexité temporelle et spatiale « pire des cas » de l'algorithme. Justifiez votre analyse en fonction des différentes étapes de l'algorithme et des structures de données utilisées.

#### **Complexité temporelle**  
L’algorithme de Dijkstra sans **Min-Heap** effectue les étapes suivantes :  

1. **Initialisation** :  
   $$O(V)$$  

2. **Recherche du sommet minimal \( u \)** :  
   À chaque itération, l'algorithme parcourt tous les sommets restants pour trouver celui ayant la plus petite distance :  
   $$O(V) \, \text{(par itération)} \quad \Rightarrow \quad O(V^2) \, \text{(pour \( V \) sommets)}.$$

3. **Mise à jour des voisins de \( u \)** :  
   Pour chaque sommet \( u \), tous ses voisins sont explorés. Le coût total est proportionnel au nombre d'arêtes :  
   $$O(E).$$

**Complexité temporelle totale** :  
$$O(V^2 + E) = O(V^2).$$

---

#### **Complexité spatiale**  
L'algorithme utilise :  
1. $$\text{dist}[], \text{pred}[], \text{sptSet}[]$$ :  
   $$O(V).$$  
2. Le graphe en liste d’adjacence :  
   $$O(V + E).$$

**Complexité spatiale totale** :  
$$O(V + E).$$  

---

**Conclusion :**
- **Temporelle** : $$O(V^2)$$  
- **Spatiale** : $$O(V + E)$$.


## 7. Proposez une version récursive de l'algorithme (ou d'une partie de celui-ci, si cela est pertinent). Formulez une hypothèse d’induction qui servira à démontrer la correction de l'algorithme sur la base des appels récursifs. Seule l’hypothèse d’induction, et son impact sur la correction de l’implémentation récursive, doit être formulée formellement ; les autres calculs peuvent être considérés corrects.

## 8. Enfin, en fonction de l’algorithme que vous aurez choisi, ajoutez des informations qui vous semblent pertinentes ou sur des aspects caractéristiques à cet algorithme qui sont précisés dans la description de l’algorithme (voir section 2 ci-dessous).







