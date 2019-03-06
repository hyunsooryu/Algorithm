class Node:
  def __init__(self, val):
    self.val = val
    self.next = None
  
  def __str__(self):
    return self.val

class LinkedList:
  def __init__(self):
    self.head = None
    self.tail = None
    self.size = 0
  
  def isEmpty(self):
    return self.size == 0
  
  def addToEnd(self, node):
    if self.isEmpty():
      self.head = node
      self.tail = node
    else:
      self.tail.next = node
      self.tail = node
    self.size += 1
  
  def __str__(self):
    n = self.head
    data_s = []
    while n != None:
      data_s.append(n.val)
      n = n.next
    return data_s
  
  def remove(self, target):
    if self.head.val == target:
      self.head = self.head.next
    else:
      n = self.head
      while n.next != None:
        if n.next.val == target:
          n.next = (n.next).next
          break
        n = n.next

        

     

LL = LinkedList()
for i in range(1, 101):
  LL.addToEnd(Node(i))

print(LL.__str__())
LL.remove(43)
print(LL.__str__())


