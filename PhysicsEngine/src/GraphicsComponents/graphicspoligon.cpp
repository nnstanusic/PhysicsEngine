#include "graphicspoligon.h"


GraphicsPoligon::GraphicsPoligon(std::string name, enFormat format)
{
    stream.open("../PhysicsEngine/Data/Objects/" + name);

    if(!stream.is_open())
    {
        std::cerr << "Couldn't open" + name << std::endl;
        exit(-1);
    }

    switch (format)
    {
        case wavefront:
            LoadWaveFront();
            break;
    }
}

GraphicsPoligon::~GraphicsPoligon()
{
    stream.close();
}

void GraphicsPoligon::LoadWaveFront()
{
    std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
    std::vector< glm::vec3 > temp_vertices;
    std::vector< glm::vec2 > temp_uvs;
    std::vector< glm::vec3 > temp_normals;



    while(stream.good())
    {
        std::string line;

        stream >> line;


        if(line == "v")
        {

            glm::vec3 vertex;
            stream >> vertex.x >> vertex.y >> vertex.z;
            temp_vertices.push_back(vertex);

        }else if( line == "vt")
        {
            glm::vec2 uv;
            stream >> uv.x >> uv.y;
            temp_uvs.push_back(uv);
        }else if(line == "vn")
        {
            glm::vec3 normal;
            stream >> normal.x >> normal.y >> normal.z;
            temp_normals.push_back(normal);
        }
        else if(line == "f")
        {

            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            std::string complicatedLine;
            std::getline(stream, complicatedLine);
            int match;


            //retard format of f what vertex/ what texture/ what normal
            match = std::sscanf(complicatedLine.c_str(),
                                "%d/%d/%d %d/%d/%d %d/%d/%d\n",
                                &vertexIndex[0], &uvIndex[0], &normalIndex[0],
                                &vertexIndex[1], &uvIndex[1], &normalIndex[1],
                                &vertexIndex[2], &uvIndex[2], &normalIndex[2]);

            if(match == 9)
            {
                vertexIndices.push_back(vertexIndex[0]);
                vertexIndices.push_back(vertexIndex[1]);
                vertexIndices.push_back(vertexIndex[2]);
                uvIndices    .push_back(uvIndex[0]);
                uvIndices    .push_back(uvIndex[1]);
                uvIndices    .push_back(uvIndex[2]);
                normalIndices.push_back(normalIndex[0]);
                normalIndices.push_back(normalIndex[1]);
                normalIndices.push_back(normalIndex[2]);
                continue;
            }


            match = std::sscanf(complicatedLine.c_str(), "%d %d %d",
                                &vertexIndex[0],
                                &vertexIndex[1],
                                &vertexIndex[2]);

            if(match == 3)
            {
                vertexIndices.push_back(vertexIndex[0]);
                vertexIndices.push_back(vertexIndex[1]);
                vertexIndices.push_back(vertexIndex[2]);
            }

        }else if(line == "#")
        {
            std::getline(stream, line);
        }
    }

    //data processing
    for( unsigned int i=0; i<vertexIndices.size(); i++ )
    {
        unsigned int vertexIndex = vertexIndices[i];
        glm::vec3 vertex = temp_vertices[ vertexIndex-1 ];
        vertices.push_back(vertex);
    }


    for( unsigned int i=0; i<uvIndices.size(); i++ )
    {
        unsigned int uvIndex = uvIndices[i];
        glm::vec2 uv = temp_uvs[ uvIndex-1 ];
        uvs.push_back(uv);
    }

    for( unsigned int i=0; i<normalIndices.size(); i++ )
    {
        unsigned int normalIndex = normalIndices[i];
        glm::vec3 normal = temp_normals[ normalIndex-1 ];
        normals.push_back(normal);
    }
}




void GraphicsPoligon::Draw()
{


    glBegin(GL_TRIANGLES);


    for(glm::vec3 vertex : vertices)
    {
        glVertex3f(vertex.x , vertex.y, vertex.z);
    }
    glEnd();


    glBegin(GL_LINE_STRIP);

        glVertex3f(0,0,-1);
        glVertex3f(0,0,1);
    glEnd();
}
