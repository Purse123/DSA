use std::boxed::Box;

#[derive(Clone)]
// template in C++ => generic in rust
struct Node<T> {
       data: T,
       // ownership over garbage collector
       // Box<Node<T>> ensure heap allocation
       prev: Option<Box<Node<T>>>,
       next: Option<Box<Node<T>>>,
}
struct DoublyLinkedList<T> {
       start: Option<Box<Node<T>>>,		// option-> Some(T) or None
       end: Option<Box<Node<T>>>,
}
impl<T: Clone + std::fmt::Display> DoublyLinkedList<T> {
	// careate a empty DoublyLinkedList
	fn new() -> Self {
	   DoublyLinkedList { start: None, end: None }
	}
	// push
	fn push(&mut self, data: T) {
	    let new_node = Box::new(Node {
		data,
		prev: self.end.take(),		// take() consume a value and replace with None
		next: None,
	    });
	    if let Some(ref mut end) = self.end{	// checking for end node
	       end.next = Some(new_node);
	    }

	    self.end = Some(new_node);

	    if self.start.is_none() {
	       // we cannot self.start = self.end bcz not allow multiple ownership,
	       // bcz it is heap-allocation
	       self.start = self.end.clone();
	    }
	}
	fn display(&self) {
	   let mut current = &self.start;
	   while let Some(node) = current {
	   	 print!("{} ", node.data);
		 current = &node.next;
	   }
	   println!();
	}
}
fn main() {
   let mut list = DoublyLinkedList::new();
   list.push(1);
   list.push(2);
   list.push(3);
   println!("Display list: ");
   list.display();
}
