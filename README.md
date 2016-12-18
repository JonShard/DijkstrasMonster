# **DijkstrasMonster**
A little SFML 2 game, created by a Norwegain student the NTNU (univeristy). Its about escaping Dijkstra's monster in a network by out-dijkstra-ing dijkstra's monster, and getting to the goal before it gets you.


###**Change log:**

#####Version 0.0		(The first kick)

- [x] An empty window can be opened.
- [ ] Press a key to generate random nodes.
- [ ] Click empty space to create a node.
- [ ] Click two nodes to connect them.
- [ ] Submit sound, Error sound, Back sound.

 





###**Ideas for stuff to add:**

- A reward system for finishing a level with a Good score.
It can reweal a new joke, displayed on screen and accessable from main menu. It can also be an image.
- Movement point pickups. The AI can considder the connections to this node to have X less wight. 
The player will probably think differently, looking at the same situaltion.
- Race mode where the Monster isn't hunting you. Its instead trying to beat you to the finish line. This mode can have mirrored nodes, so the Goal node is shared, and a mirror plane goes through the goal node: S=start, G=goal, N=node, "- \ /"=connection.

   N       N
  / \     / \
 N---N-G-N---N
 |           |
 S      	 S