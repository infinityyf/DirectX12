#pragma once

#ifndef MODEL_LOADER_H
#define MODEL_LOADER_H
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>//���ڶԶ�ȡ��ģ���ļ����к���

#include "stdafx.h"

using namespace Assimp;
using namespace std;
using namespace DirectX;	//ʹ����ѧ��

struct Vertex {
	XMFLOAT3 position;	//λ��
	XMFLOAT3 normal;	//����
	XMFLOAT2 texcoord;	//��ͼ����
};

struct Texture {
	UINT id;
	wstring type;
};

struct Mesh {
public:
	vector<Vertex> vertexs;
	vector<UINT> indices;
	vector<Texture> textures;

	Mesh(vector<Vertex> vertexs,vector<UINT> indices,vector<Texture> textures);
};


class Model {
public:
	Model(string modelPath) {
		this->LoadModel(modelPath);
	}
private:
	void LoadModel(string modelPath);
	void ProcessNode(aiNode* node,const aiScene* scene);	//����ڵ�
	Mesh ProcessMesh(aiMesh* mesh,const aiScene* scene);	//����mesh
	vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);

	vector<Mesh> Meshes;
};


#endif // !MODEL_LOADER_H
