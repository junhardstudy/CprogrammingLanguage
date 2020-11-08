# 개요

1. Graph를 adjacency matrix와 adjacency list를 이용하여 구현합니다.

2. 1에서 구현한 것을 이용하여, input file로 부터 데이터를 입력받아 graph에 저장한 후, DFS와 BFS로 출력합니다.

3. Adjacency list에 그래프의 가중치를 추가하여 구현 해 봅니다.

4. 3에서 구현된 graph를 이용하여 특정 input파일을 받아 minimum spanning tree와 Dikstra 알고리즘을 이용하여 shortest path를 구합니다.

## Graph

> 모든 node(vertex)들이 edge(arc)에 의해 연결된 형태입니다. 

1. Directed graph : 간선에 방향성이 있는 그래프로, vertex와 arc를 가집니다.

2. Undirected graph : 간선에 방향성이 없는 그래프로, node와 edge를 가집니다.

정점(node, or vertex)의 집합을 V, 간선(edge, arc)의 집합을 E라고 하면 아래와 같이 그래프를 표현할 수 있습니다.

> G = (V, E) 

Terminology

1. Path : 인접한 노드로 구성된 일련의 sequence

2. Cycle : 어떤 노드에서 시작해 다른 노드를 거치지 않고 바로 자기 자신 노드에서 끝나는 경로(path)

3. Loop : 간선의 end point가 같은 경우

4. Complete Graph : 주어진 node에 대해서 최대한의 edge를 가지는 graph

## Adjacency matrix

Graph의 node(or vertex)와 edge(arc)를 2 dimensional의 array로 나타낸 형태입니다.

![그림](t.jpg)

## Adjacency list

Graph의 node(or vertex)와 edge(arc)를 리스트로 나타낸 형태입니다. 소스코드에서는 링크드 리스트로 구현되어 있는것을 확인할 수 있습니다.

![그림](t.jpg)

## Graph에 대한 탐색(traversal) 방법

1. DFS

인접 node를 탐색하기 전에, 해당 vertex의 자식 node들을 먼저 탐색하는 방법입니다.

자식 node들을 탐색하고 나면, 부모 node로 돌아와야 하는 backtracking이 필요합니다.

backtracking은 재귀호출을 이용하거나, 스택으로 구현할 수 있습니다.

![그림](t.jpg)

2. BFS

해당 node의 다음 level을 탐색하기 전에, 인접한 모든 vertex를 먼저 탐색하는 방법입니다.

어떤 node의 인접한 행렬들을 먼저 탐색하므로 queue를 이용하여 구현할 수 있습니다.

![그림](t.jpg)

## Minimum spanning tree

최소 신장 트리(MST)로서, 그래프의 모든 node(or vertex)를 포함하면서 최소한의 연결(edge, or arc)을 가지고, 그 때의 간선들의 가중치(weight)의 합이 최소가 되는 subgraph입니다.

즉, 다음과 같은 condition을 만족해야 합니다.

1. n개의 정점을 가진 어떤 그래프 G가 MST가 되려면, n-1개의 간선을 가져야 합니다. 이는 트리 형태가 됨을 의미합니다.

2. 어떤 그래프 G가 MST가 되려면, simple cycle이 없어야 합니다.

이 과제에서는 Prim 알고리즘을 사용하여 구현하였습니다.


## Dikstra's algorithm

최단 경로(shortest path)를 찾는 알고리즘입니다.

***

## 소스코드

```c

```

## 결과