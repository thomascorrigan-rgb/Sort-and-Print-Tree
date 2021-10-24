class BinarySearchTree {
  private:
    void coursesInOrder(Node* node);
  public:
  	void CoursesInOrder();
  	Course SearchCourses(string bidId);
  	void DisplayCourse(Course course);
    void DisplayCourseIdAndName(Course course)
  
/**
 * Traverse the tree in order
 */
void BinarySearchTree::CoursesInOrder() {
	// In order root
	// call coursesInOrder fuction and pass root 
	this->coursesInOrder(root);
}
  
/**
 * Search courses for course ID
 *
 * @param string course ID
 */
Course BinarySearchTree::SearchCourses(string courseID) {
	// Implement searching the tree for a bid
	// set current node equal to root
	Node* current = root;


	// keep looping downwards until bottom reached or matching bidId found
	while (current != nullptr) {
		// if match found, return current bid
		if (current->course.courseID.compare(courseID) == 0) {
			return current->course;
		}
		// if bid is smaller than current node then traverse left
		if (courseID.compare(current->course.courseID) < 0) {
			current = current->left;
		}
		else {
			// else larger so traverse right
			current = current->right;
		}
	}


	Course course;
	return course;
}



/**
 * Display the courses in order by traversing tree
 *
 * @param node struct containing the current tree node
 */
void BinarySearchTree::coursesInOrder(Node* node) {
	//if node is not equal to null ptr
	if (node != nullptr) {
		//InOrder not left
		coursesInOrder(node->left);
		//output course ID and name
		DisplayCourseIdAndName(node->course);
		//InOder right
		coursesInOrder(node->right);
	}
}

/**
 * Display the course information  and prerequisites to the console
 *
 * @param course struct containing the course info
 */
void BinarySearchTree::DisplayCourse(Course course) {
	//display course ID and course name
	cout << course.courseID << ", " << course.courseName;
	//If there is at least one prerequisite
	if (!(course.firstPrerequisite.empty())) {
		//display first prerequisite
		cout << endl << "Prerequisites: " << course.firstPrerequisite;
		//if there is a second prerequisite
		if (!(course.secondPrerequisite.empty())) {
			//display second prerequisite
			cout << ", " << course.secondPrerequisite;
		}
	}
	//if no prerequisites
	else {
		cout << endl << "No prerequisites for this course.";
	}
	cout << endl << endl;
	return;
}

/**
 * Display the course id and name to the console
 *
 * @param course struct containing the course info
 */
void BinarySearchTree::DisplayCourseIdAndName(Course course) {
	//display course ID and course name
	cout << course.courseID << ", " << course.courseName << endl;
	return;
}