#include "Node.h"
#include "maths_funcs.h"

Node::Node()
	:parent(0)
{ ; }

void Node::init() { 
	position = vec3(0, 0, 0);
	rotation = versor(0,0,0,1);
	scale = vec3(1,1,1);

	localMatrix = identity_mat4();
	worldMatrix = identity_mat4();
	localInverseMatrix = identity_mat4();
	worldInverseMatrix = identity_mat4();
}

void Node::addChild(Node& node) { 
	node.parent = this;
	children.push_back(&node);
}

void Node::removeChild(Node& node) { 
	auto it = std::find(children.begin(), children.end(), &node);
	if (it != children.end()) {
		node.parent = nullptr;
		children.erase(it);
	}
}

void  Node::updateLocal() 
{ 
	//T = translacion segun position
	mat4 T = translate(identity_mat4(), position);
	//R = rotacion segun rotation
	mat4 R = quat_to_mat4(rotation);
	//S = escala segun scale
	mat4 S = scaler(identity_mat4(), scale);

	//Tinv = translacion inversa segun position
	mat4 Tinv = translate(identity_mat4(), vec3(-position.v[0], -position.v[1], -position.v[2]));
	//Rinv = rotación inversa segun rotation(¿es R ortogonal ? recuerda que inverse(A) = transpose(A) si A es ortogonal)
	//Sinv = escala inversa segun scale
	mat4 Sinv = scaler(identity_mat4(), vec3(1/scale.v[0], 1/scale.v[1], 1/scale.v[2]));

	localMatrix = T*R*S;
	localInverseMatrix = Sinv*transpose(R)*Tinv;
}

void  Node::updateHierarchy()
{
	updateLocal();
	mat4 parentMatrix = identity_mat4();
	mat4 parentInverseMatrix = identity_mat4();
	if (parent!= nullptr) {
		parentMatrix = (*parent).worldMatrix;
		parentInverseMatrix = (*parent).worldInverseMatrix;
	}
	worldMatrix = parentMatrix*localMatrix;
	worldInverseMatrix = parentInverseMatrix*localInverseMatrix;

	for (size_t i = 0; i < children.size(); ++i) {
		Node* child = children[i];
		if (child != nullptr) {
			(*child).updateHierarchy();
		}
	}
}
