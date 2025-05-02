


void vector_init (Vector* this) {
	if(!this) {
	    return;
	}
	this->data = NULL;
	this->size = 0;
	return;
}

void vector_init_size(Vector* this, size_t n) {
	if (!this) {
	     return;
	}
	this->data = (int*)malloc(n * sizeof(int));
	this->capacity = n;

	return;
	
}
void vector_init_fill(Vector* this, size_t n,  int value) {
	if(!this){
		return;
	}
	this->data = (int*)malloc(n * sizeof(int));
	this->capacity = n;
	this->size = n;
	
	for (int i = 0; i < n; ++i) {
		this->data[i] = value;
	} 
	return;
}

void vector_destroy(Vector* this) {
	if (!this) {
	     return;
	}
	free(this->data);
	this->data = NULL;
	this->size = 0;
	this->capacity = 0;

	return;
}

void vector_copy (Vector* this, const Vector* other) {
	if(!this || !other) {
	     return;
	}
	this->size = other->size;
	this->capacity = other->capacity;
	this->data = (int*)malloc(other->capacity * sizeof(int));

	for(size_t i = 0; i < other->size; ++i) {
		
		this->data[i] = other->data[i];
	}	
	
	return;
}

Vector* vector_assign(Vector* dest, const Vector* src) {
	if(!dest || !src) {
	    return dest;
	}
	free(dest->data);
	return vector_copy(dest, src);
}
int* vector_at(Vector* v, size_t index) {
	if(!v) {
	  return NULL;
	}
	
	if(index >= v->size) {
	  return NULL;
	}
	
	if(!(v->data)) {
          return NULL;
	}
	return v->data + index;
}

int* vector_front(Vector* v) {
	if(!v) {
	 return NULL;
	}
	return v->data;
}
int* vector_back(Vector* v) {
	if(!v) {
          return NULL;
	}
	return v->data + v->size;
}

int vector_empty(const Vector* V) {
	if(!(V->size)) {
		return 1;
	}
	return 0;
}

size_t vector_size(const Vector * v) {
	
	 return v->size;
	
}

size_t vector_capacity(const Vector* v) {
	return v->capacity;
}

void vector_reserve(Vector* v, size_t new_cap) {
	if(!v) {
	  return;
	}

	if(new_cap < v->capacity) {
	  return;
	}
	return v->capacity = new_cap;
}
void vector_clear (Vector* v) {

	for(int i = 0; i < v->size; ++i) {
		v->data[i] = 0;
	}
	v->size = 0;
	return;
}

void vector_push_back(Vector* v, int value) {
	if(!v) {
	  return;
	}
	if(v->size >= v->capacity) {
		v->capacity *= 2; 
	
	v->data = (int*)realloc(v->data, v->capacity* sizeof(int));
	}
	v->data[size - 1] = value;

	return;
}
void vector_pop_back(Vector* v) {
	if(!v) {
	  return;
	}
	if(!(v->size)) {
	   return;
	}
	(v->size)--;
	return;
}
void vector_insert(Vector* v, size_t pos, int value) {
	if(!v) {
	  return;
	}
	if(pos >= v->size) {
	return;
	}
	
	if(v->size >= v->capacity) {
		 v->capacity *= 2;

		v->data = (int*)realloc(v->data, v->capacity); 
	}

	for (size_t i = v->size; i>pos; ++i) {
		v->data[i] = v->data[i - 1];
	}
	v->size += 1;
	v->data[pos] = value;

	return;
}

void vector_erase(Vector* v, size_t pos) {
	if(!v) {
	   return ;
	}
	if(pos > v->size) {
	   return;
	}

	for (size_t i = pos; i < (v->size) - 1; ++i) {
		v->data[i] = v->data[i + 1];;
	}

	v->size -= 1;
	return;
}

void vector_swap(Vector* v1,  Vector* v2) {
	if (v1 == NULL || v2 == NULL) {
		return;
	}
	size_t x;
	int*ptr;

	ptr = v1->data;
	v1->data = v2->data;
	v2->data = ptr;

	x = v1->size;
	v1->size = v2->size;
        v2->size = x;

	x = v1->capacity;
	v1->capacity = v2->capacity;
	v2->capacity = x;	
}

void vector_resize(Vector* v, size_t count) {
	if(!v) {
	  return;
	}
	if(count > v->capacity) {
		v->data = (int*)realloc(v->data,count * sizeof(int));

	}
	v->size = count;
	return;
}
