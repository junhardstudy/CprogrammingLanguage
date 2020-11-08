# 개요

## Binary Search Tree

1. left subtree에 있는 모든 Node들은 right subtree에 있는 모든 Node들보다 크기가 반드시 작아야합니다.

2. 모든 subtree는 binary tree구조 형태를 취하고 있어야 합니다.

요구되는 연산은 앞의 챕터에서 배웠던 complete binary search와 유사하지만, Node의 입력(insert)과 삭제(delete)가 다릅니다.

Node가 추가되거나 삭제될때, binary search tree의 속성을 만족해야 하기 때문입니다.

<tabble>
<tr>
<td>

### 1. Insert

새로운 트리에 추가하게 된다면, 단순히 트리의 root에 Node를 추가하면 되지만, 1개 이상의 Node가 존재되어 있는 이진 트리에 새로운 Node를
추가해야 한다면 비교가 필요합니다.

![r1](./image/1.png)

위와 같은 이진 트리 조건을 가질 때, 새로운 노드 5을 추가하는 과정입니다.

![r3](./image/3.png)

먼저, root Node와 비교를 하게 됩니다. 새로운 Node의 값 5는 root Node보다 작으므로, 작은 값이 위치한 왼족 subtree로 탐색을 이동
합니다.
 
![r4](./image/4.png)

이번에는 4의 값을 가진 Node와 비교합니다. 추가하려는 Node의 값이 보다 크므로, 이번에는 오른쪽 subtree로 탐색을 이동합니다.

![r4](./image/5.png)

이번에는 8의 값을 가진 Node와 비교합니다. 추가하려는 Node의 값이 보다 작으므로, 이번에는 왼쪽 subtree로 이동해야합니다. 하지만 leaft
Node조건 이므로 왼쪽 Node에 새로운 Node를 추가하게됩니다.

![r5](./image/6.png)

트리의 깊이가 h라면, 연산 시간에대한 최대 boundary는 O(h)가 됩니다.

</td>
</tr>

<tr>
<td>

### 2. Delete

Delete연산의 경우, tree의 속성을 만족시키면서 Node의 제거가 이루어져야 합니다. 따라서 발생할 수 있는 4가지 case에 대한 delete처리는
아래와 같습니다.

1. 삭제할 Node가 leaf Node인 경우, 단순히 leaft Node를 제거해주면 됩니다. 단, 부모 Node에서 연결되어 있던 link에 대해서는 끊어졌(Null)다는 것을 명시할 필요가 있습니다.

2. 삭제할 Node가 left subtree만 가지고 있는 경우 입니다. 해당 Node를 삭제하고, 삭제된 Node의 자리는 left child Node로 대체합니다.

3. 삭제할 Node가 right subtree만 가지고 있는 경우 입니다. 해당 Node를 삭제하고, 삭제된 Node의 자리는 right child Node로 대체합니다.

4. 삭제할 Node가 left subtree와 right subtree 둘 다 가지고 있는 경우 입니다. 이 경우, 삭제되는 Node의 <strong>left subtree중 가장 큰 값</strong>을 가져오거나, <strong>right subtree중 가장 작은 값</strong>이 삭제된 Node의 자리를 대체합니다.

</td>
</tr>

</table>

## Generic Coding



## 소스코드

## 결과