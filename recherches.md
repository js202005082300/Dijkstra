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

## 2. Spécifiez le problème : explicitez les préconditions et postconditions formellement (en respectant les notations mathématiques vues au cours).

- Spécification du programme suivant
- environnement
int V, E, src;
int graph[V][V]; // Matrice d'adjacence pour représenter le graphe
int dist[V]; // Tableau des distances
- précondition
pré ≡ V = V0 > 0 ∧ E = E0 ≥ 0 ∧ src = src0 ∧ ∀i,j (0 ≤ i,j < V0) : graph[i][j] ≥ 0
( V ) est le nombre de sommets et doit être positif.
( E ) est le nombre d'arêtes et doit être non négatif.
( src ) est le sommet source.
Les poids des arêtes dans la matrice d'adjacence doivent être non négatifs.
- postcondition
post ≡ ∀v (0 ≤ v < V0) : dist[v] = min(∑_{(u,w) ∈ P} graph[u][w]) où P est un chemin de src0 à v

Pour chaque sommet ( v ), ( dist[v] ) contient la distance minimale depuis le sommet source ( src0 ) jusqu'à ( v ).

## 3. Implémentez l'algorithme en C. Vous êtes autorisés à vous aider des ressources que vous trouvez, mais l’implémentation doit être votre propre travail : vous devez vous l’approprier et en maîtriser tous les détails. Dans le rapport, vous donnerez le code (commenté) de votre implémentation, vous détaillerez les structures de données utilisées et expliquer pourquoi elles sont adaptées à l'algorithme choisi.

+ Structures de données associées


## 4. En vos propres mots, expliquez comment fonctionne l'algorithme. Décrivez de manière intuitive pourquoi l’implémentation produit un résultat correct par rapport à vos spécifications.

## 5. Identifiez un invariant de boucle pertinent pour l'algorithme. Formulez cet invariant et démontrez, de manière formelle, qu'il est vérifié à chaque itération de la boucle concernée. Expliquez en quoi il permettrait, dans une preuve de programme plus complète, de faire le pont entre pré- et post- conditions.

## 6. Analysez la complexité temporelle et spatiale « pire des cas » de l'algorithme. Justifiez votre analyse en fonction des différentes étapes de l'algorithme et des structures de données utilisées.

+ Complexité temporelle et spatiale :

Analyse des performances dans différents contextes de graphe (dense, sparse).

Complexity analysis (O(V + E log V))

+ de temps
Soit n sommets et a arcs, on a :
O((a+n)log n)
<=> O(a+nlog n) *simplification pour l'implémentation avec un tas de Fibonacci ce qui améliore le temps asymptotique de l'algorithme de Dijkstra et de l'algorithme de Prim (calcul l'arbre couvrant de pods minimal d'un graphe).

A vérifier !
Complexité : En 𝑂(𝑉²) avec une matrice d’adjacence, optimisée en 𝑂(𝐸log𝑉) avec un tas min et une liste d’adjacence.

+ Comparaison en termes de complexité
++ Temps d’exécution :
A* et Dijkstra : O(E+VlogV) pour les graphes avec files de priorité.
Bellman-Ford : O(V×E), ce qui est plus lourd en termes de traitement pour de grands graphes.
++ Capacité de traitement :
A* et Dijkstra nécessitent que tous les poids soient positifs.
Bellman-Ford accepte des poids négatifs, mais au prix d'une complexité temporelle accrue.

## 7. Proposez une version récursive de l'algorithme (ou d'une partie de celui-ci, si cela est pertinent). Formulez une hypothèse d’induction qui servira à démontrer la correction de l'algorithme sur la base des appels récursifs. Seule l’hypothèse d’induction, et son impact sur la correction de l’implémentation récursive, doit être formulée formellement ; les autres calculs peuvent être considérés corrects.

## 8. Enfin, en fonction de l’algorithme que vous aurez choisi, ajoutez des informations qui vous semblent pertinentes ou sur des aspects caractéristiques à cet algorithme qui sont précisés dans la description de l’algorithme (voir section 2 ci-dessous).







