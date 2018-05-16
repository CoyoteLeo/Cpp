parent = table[1...n] // n elements and set each element parent to zero(represent not used)

MAKE_TREE(v):
    parent[v] = v

GRAFT(r,v):
    parent[r] = v

FIND_DEPTH(v):
    dep = 0
    while(parent[v] != v):
        dep = dep + 1
        v = parent[v]
    return dep
 
