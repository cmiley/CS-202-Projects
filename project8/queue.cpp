class charqueue{
	public:
		//constructors
		void enqueue(); //put something into queue
		char dequeue(); //take something from the queue
		bool isempty(); //check if queue is empty
		bool isfull(); //check if queue is full
		void clear(); //clear queue

	private:
		int front;
		int rear;
		int max;
		char* data; //the actual array
};
