/*
 * Copyright (c) 2006-2009 Erin Catto http://www.box2d.org
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

/* 
 * Base code for CS 251 Software Systems Lab 
 * Department of Computer Science and Engineering, IIT Bombay
 * 
 */


#include "cs251_base.hpp"
#include "render.hpp"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include "GL/freeglut.h"
#endif

#include <cstring>
using namespace std;

#include "dominos.hpp"

namespace cs251
{
  /**  The is the constructor 
   * This is the documentation block for the constructor.
   */ 
  
  dominos_t::dominos_t()
  {
    //Ground
    /*! \section  Ground 
     * Variables in this section are :
     *  <br>
     */ 
     /// \b shape -> creates an edge-like shape for the ground(type b2EdgeShape)  <br>
     /// \b shape -> (value) its end points are set to (-90,0) and (90,0)  <br>  <br>
     /// \b bd -> holds all data to construct a body (type b2EdgeShape)  <br>  <br>
     /// \b b1 -> body created in the world using bd (type b2Body*) <br>
     /// \b b1 -> edge shape attached to it and density value intialized to zero  <br>  <br>
    b2Body* b1;  
    {
      
      b2EdgeShape shape; 
      shape.Set(b2Vec2(-90.0f, 0.0f), b2Vec2(90.0f, 0.0f));
      b2BodyDef bd; 
      b1 = m_world->CreateBody(&bd); 
      b1->CreateFixture(&shape, 0.0f);
    }
          
    /*! \section The Top horizontal shelf
     *  Variables in this section are:
     *  <br>
     */
     /// \b  shape -> creates a convex polygon shape (type b2PolygonShape)  <br>
     /// \b  shape -> it is set as box with half-width=6.0 and half-height=0.25  <br>  <br>
     /// \b  bd -> holds data to construct a body (type b2BodyDef)  <br> 
     /// \b  bd -> its position is set to (-31.0,30.0)  <br>  <br>
     /// \b  ground -> object created in world using bd (type b2Body*)  <br>
     /// \b  ground -> box shape attached to itand density setto zero  <br>  <br>
     // top horizontal shelf
    {
      b2PolygonShape shape;
      shape.SetAsBox(6.0f, 0.25f);
	
      b2BodyDef bd;
      bd.position.Set(-31.0f, 30.0f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
    }
    
    /*! \section Dominos
     *  Variables in this section are:
     *  <br>
     */
     /// \b  shape -> creates a convex polygon shape (type b2PolygonShape)  <br>
     /// \b  shape -> it is set as box with half-width=0.1 and half-height=1.0  <br>  <br>
     /// \b  fd -> creates a fixture (type b2FixtureDef)  <br>
     /// \b  fd -> shape to box,density=20.0,friction=0.1  <br>  <br>
     /// \b  bd -> holds data to construct a body (type b2BodyDef)  <br> 
     /// \b  bd -> its position is set according to i and it is dynamic body  <br>  <br>
     /// \b  body -> object created in world using bd (type b2Body*)  <br>
     /// \b  body -> fixtures is attached to body  <br>  <br>

    {
      b2PolygonShape shape;
      shape.SetAsBox(0.1f, 1.0f);
	
      b2FixtureDef fd;
      fd.shape = &shape;
      fd.density = 20.0f;
      fd.friction = 0.1f;
		
      for (int i = 0; i < 10; ++i)
	{
	  b2BodyDef bd;
	  bd.type = b2_dynamicBody;
	  bd.position.Set(-35.5f + 1.0f * i, 31.25f);
	  b2Body* body = m_world->CreateBody(&bd);
	  body->CreateFixture(&fd);
	}
    }


        /*! \section b4
     *  Variables in this section are:
     *  <br>
     */
     /// \b  shape -> creates a convex polygon shape (type b2PolygonShape)  <br>
     /// \b  shape -> it is set as box with half-width=0.25 and half-height=0.25  <br>  <br>
     /// \b  bd -> holds data to construct a body (type b2BodyDef)  <br> 
     /// \b  bd -> its position is set to (-40,33.0)  <br>  <br>
     /// \b  b4 -> object created in world using bd (type b2Body*)  <br>
     /// \b  b4 -> shape is attached to body and density to 2.0 <br>  <br>  


    b2Body* b4;
    {
      b2PolygonShape shape;
      shape.SetAsBox(0.25f, 0.25f);
	  
      b2BodyDef bd;
      bd.type = b2_dynamicBody;
      bd.position.Set(-40.0f, 33.0f);
      b4 = m_world->CreateBody(&bd);
      b4->CreateFixture(&shape, 2.0f);
    }
	
        /*! \section Pendulum
     *  Variables in this section are:
     *  <br>
     */
     /// \b  shape -> creates a convex polygon shape (type b2PolygonShape)  <br>
     /// \b  shape -> it is set as box with half-width=0.25 and half-height=1.5  <br>  <br>
     /// \b  bd -> holds data to construct a body (type b2BodyDef)  <br> 
     /// \b  bd -> its position is set to (-36.5,28.0)  <br>  <br>
     /// \b  b2 -> object created in world using bd (type b2Body*)  <br>
     /// \b  b2 -> shape is attached to body and density to 10.0 <br>  <br>  


    //The pendulum that knocks the dominos off
    {
      b2Body* b2;
      {
	b2PolygonShape shape;
	shape.SetAsBox(0.25f, 1.5f);
	  
	b2BodyDef bd;
	bd.position.Set(-36.5f, 28.0f);
	b2 = m_world->CreateBody(&bd);
	b2->CreateFixture(&shape, 10.0f);
      }
	

        /*! \section The another horizontal shelf
     *  Variables in this section are:
     *  <br>
     */
     /// \b  shape -> creates a convex polygon shape (type b2PolygonShape)  <br>
     /// \b  shape -> it is set as box with half-width=7 and half-height=0.25 and centre(-20,20) and angle 0 degree  <br>  <br>
     /// \b  bd -> holds data to construct a body (type b2BodyDef)  <br> 
     /// \b  bd -> its position is set to (1.0,6.0)  <br>  <br>
     /// \b  ground -> object created in world using bd (type b2Body*)  <br>
     /// \b  ground -> shape is attached to body and density to 0.0 <br>  <br>
     /// \b  anchor -> (type b2Vec2) it is like a vector position  <br>
     /// \b  anchor -> its value is set to (-37,40)  <br>  <br>
     /// \b  jd -> (type b2RevoluteJointDef)  <br>
     /// \b  jd -> it is intialised using b2,b4,anchor  <br>  <br>

      //Another horizontal shelf
      {
	b2PolygonShape shape;
	shape.SetAsBox(7.0f, 0.25f, b2Vec2(-20.f,20.f), 0.0f);
	
	b2BodyDef bd;
	bd.position.Set(1.0f, 6.0f);
	b2Body* ground = m_world->CreateBody(&bd);
	ground->CreateFixture(&shape, 0.0f);
      }

      b2RevoluteJointDef jd;
      b2Vec2 anchor;
      anchor.Set(-37.0f, 40.0f);
      jd.Initialize(b2, b4, anchor);
      m_world->CreateJoint(&jd);
    }


    /*! \section the4 train of small spheres (not now changed in lab3)
     *  Variables in this section are:
     *  <br>
     */
     /// \b  circle -> creates a circle shape (type b2CircleShape)  <br>
     /// \b  circle -> it is set as circle with radius=0.5  <br>  <br>
     /// \b  ballfd -> creates a fixture (type b2FixtureDef)  <br>
     /// \b  ballfd -> shape to circle,density=1.0,friction=0.0,restitution=0  <br>  <br>
     /// \b  ballbd -> holds data to construct a body (type b2BodyDef)  <br> 
     /// \b  ballbd -> its position is set according to i and it is dynamic body  <br>  <br>
     /// \b  spherebody -> object created in world using bd (type b2Body*)  <br>
     /// \b  spherebody -> fixtures is attached to body  <br>  <br>

      
    //The train of small spheres
    {
      b2Body* spherebody;
	
      b2CircleShape circle;
      circle.m_radius = 0.5;
	
      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 13.5f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;
	
      for (int i = 0; i < 1; ++i)
	{
	  b2BodyDef ballbd;
	  ballbd.type = b2_dynamicBody;
	  ballbd.position.Set(-22.2f + i*1.0, 26.6f);
	  spherebody = m_world->CreateBody(&ballbd);
	  spherebody->CreateFixture(&ballfd);
	}
    }

    /*! \section the3 pulley system
     *  Variables in this section are:
     *  <br>
     */
     /// \b  bs1 -> creates a convex polygon shape (type b2PolygonShape)  <br>
     /// \b  bs1 -> set it as box of half-width=2 , half-height=0.2,centre(0,-1.9),angle=0  <br>  <br>
     /// \b  bs2 -> creates a convex polygon shape (type b2PolygonShape)  <br>
     /// \b  bs2 -> set it as box of half-width=0.2 , half-height=2,centre(2.0,0),angle=0  <br>  <br>
     /// \b  bs3 -> creates a convex polygon shape (type b2PolygonShape)  <br>
     /// \b  bs3 -> set it as box of half-width=0.2 , half-height=2.0,centre(2.0,0),angle=0  <br>  <br>
     /// \b  fd1 -> creates a fixture (type b2FixtureDef)  <br>
     /// \b  fd1 -> shape to circle,density=10.0,friction=0.5,restitution=0  <br>  <br>
     /// \b  fd2 -> creates a fixture (type b2FixtureDef)  <br>
     /// \b  fd2 -> shape to circle,density=10.0,friction=0.5,restitution=0  <br>  <br>
     /// \b  fd3 -> creates a fixture (type b2FixtureDef)  <br>
     /// \b  fd3 -> shape to circle,density=10.0,friction=0.5,restitution=0  <br>  <br>
     /// \b  bd -> holds data to construct a body (type b2BodyDef)  <br> 
     /// \b  bd -> its position is set (-10,15) and it is dynamic body, can't rotation   <br>  <br>
     /// \b  box1 -> object created in world using bd (type b2Body*)  <br>
     /// \b  box1 -> fixtures is attached to body  <br>  <br>
     /// \b  box2 -> object created in world using bd (type b2Body*)  <br>
     /// \b  box2 -> fixtures is attached to body and position(10,15),density=34  <br>  <br>
     /// \b  worldAnchorOnBody1 -> Anchor point on body 1 in world axis  <br>
     /// \b  worldAnchorOnBody1 -> position set to (-10,15)  <br>  <br>
     /// \b  worldAnchorOnBody2 -> Anchor point on body 2 in world axis  <br>
     /// \b  worldAnchorOnBody2 -> position set to (10,15)  <br>  <br>
     /// \b  worldAnchorOnBody1 -> Anchor point for ground 1 in world axis  <br>
     /// \b  worldAnchorOnBody1 -> position set to (-10,20)  <br>  <br>
     /// \b  worldAnchorOnBody1 -> Anchor point for ground 2 in world axis  <br>
     /// \b  worldAnchorOnBody1 -> position set to (10,20)  <br>  <br>
     /// \b  myjoint -> (type b2PulleyJointDef)  <br>  <br>

    //The pulley system
    {
      b2BodyDef *bd = new b2BodyDef;
      bd->type = b2_dynamicBody;
      bd->position.Set(-10,15);
      bd->fixedRotation = true;
      
      //The open box
      b2FixtureDef *fd1 = new b2FixtureDef;
      fd1->density = 10.0;
      fd1->friction = 0.5;
      fd1->restitution = 0.f;
      fd1->shape = new b2PolygonShape;
      b2PolygonShape bs1;
      bs1.SetAsBox(2,0.2, b2Vec2(0.f,-1.9f), 0);
      fd1->shape = &bs1;
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.0;
      fd2->friction = 0.5;
      fd2->restitution = 0.f;
      fd2->shape = new b2PolygonShape;
      b2PolygonShape bs2;
      bs2.SetAsBox(0.2,2, b2Vec2(2.0f,0.f), 0);
      fd2->shape = &bs2;
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 10.0;
      fd3->friction = 0.5;
      fd3->restitution = 0.f;
      fd3->shape = new b2PolygonShape;
      b2PolygonShape bs3;
      bs3.SetAsBox(0.2,2, b2Vec2(-2.0f,0.f), 0);
      fd3->shape = &bs3;
       
      b2Body* box1 = m_world->CreateBody(bd);
      box1->CreateFixture(fd1);
      box1->CreateFixture(fd2);
      box1->CreateFixture(fd3);

      //The bar
      bd->position.Set(10,15);	
      fd1->density = 34.0;	  
      b2Body* box2 = m_world->CreateBody(bd);
      box2->CreateFixture(fd1);

      // The pulley joint
      b2PulleyJointDef* myjoint = new b2PulleyJointDef();
      b2Vec2 worldAnchorOnBody1(-10, 15); // Anchor point on body 1 in world axis
      b2Vec2 worldAnchorOnBody2(10, 15); // Anchor point on body 2 in world axis
      b2Vec2 worldAnchorGround1(-10, 20); // Anchor point for ground 1 in world axis
      b2Vec2 worldAnchorGround2(10, 20); // Anchor point for ground 2 in world axis
      float32 ratio = 1.0f; // Define ratio
      myjoint->Initialize(box1, box2, worldAnchorGround1, worldAnchorGround2, box1->GetWorldCenter(), box2->GetWorldCenter(), ratio);
      m_world->CreateJoint(myjoint);
    }

    //The revolving horizontal platform
    {
      b2PolygonShape shape;
      shape.SetAsBox(2.2f, 0.2f);
	
      b2BodyDef bd;
      bd.position.Set(14.0f, 14.0f);
      bd.type = b2_dynamicBody;
      b2Body* body = m_world->CreateBody(&bd);
      b2FixtureDef *fd = new b2FixtureDef;
      fd->density = 1.f;
      fd->shape = new b2PolygonShape;
      fd->shape = &shape;
      body->CreateFixture(fd);

      b2PolygonShape shape2;
      shape2.SetAsBox(0.2f, 2.0f);
      b2BodyDef bd2;
      bd2.position.Set(14.0f, 16.0f);
      b2Body* body2 = m_world->CreateBody(&bd2);

      b2RevoluteJointDef jointDef;
      jointDef.bodyA = body;
      jointDef.bodyB = body2;
      jointDef.localAnchorA.Set(0,0);
      jointDef.localAnchorB.Set(0,0);
      jointDef.collideConnected = false;
      m_world->CreateJoint(&jointDef);
    }

    /*! \section the2 heavy sphere
     *  Variables in this section are:
     *  <br>
     */
     /// \b  circle -> creates a circle shape (type b2CircleShape)  <br>
     /// \b  circle -> it is set as circle with radius=1.0  <br>  <br>
     /// \b  ballfd -> creates a fixture (type b2FixtureDef)  <br>
     /// \b  ballfd -> shape to circle,density=50.0,friction=0.0,restitution=0  <br>  <br>
     /// \b  ballbd -> holds data to construct a body (type b2BodyDef)  <br> 
     /// \b  ballbd -> its position is set to (14.0,18.0) and it is dynamic body  <br>  <br>
     /// \b  sbody -> object created in world using bd (type b2Body*)  <br>
     /// \b  sbody -> fixtures is attached to body  <br>  <br>


    //The heavy sphere on the platform
    {
      b2Body* sbody;
      b2CircleShape circle;
      circle.m_radius = 1.0;
	
      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 50.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;
      b2BodyDef ballbd;
      ballbd.type = b2_dynamicBody;
      ballbd.position.Set(14.0f, 18.0f);
      sbody = m_world->CreateBody(&ballbd);
      sbody->CreateFixture(&ballfd);
    }

/*! \section the1 see saw system
     *  Variables in this section are:
     *  <br>
     */
     /// \b  poly -> (type b2PolygonShape) to create a concave polygon  <br>
     /// \b  poly -> its vertex value are (-1,0) (1,0) (0,1.5)  <br> <br>
     /// \b  wedgefd -> (type FixtureDef) to attach properties to object  <br>
     /// \b  wedgefd -> shape=poly(triangle) , density=10.0,friction=0,restitution=0  <br> <br>
     /// \b  wedgebd -> (type b2BodyDef) it has necessary info to make objects  <br>
     /// \b  wedgebd ->  position set to (30,0)  <br> <br>
     /// \b  sbody -> (type b2Body*)  <br> <br>
     /// \b  shape -> (type b2PolygonShape) to create a concave polygon  <br>
     /// \b  shape -> it is set as box with half-width=15.0f and half-height= 0.2 <br> <br>
     /// \b  bd2 -> (type b2BodyDef) <br>
     /// \b  bd2 -> its position is set to (30,1.5) and set it as dynamic body <br> <br>
     /// \b  fd2 -> (type FixtureDef) to attach properties to object <br>
     /// \b  fd2 -> shape as box , density=1.0 <br> <br>
     /// \b  shape2 -> (type b2PolygonShape) to create a concave polygon  <br>
     /// \b  shape2 -> it is set as box with half-width=2.0f and half-height= 2 <br> <br>
     /// \b  bd3 -> (type b2BodyDef) <br>
     /// \b  bd3 -> its position is set to (40,2) and set it as dynamic body <br> <br>
     /// \b  fd3 -> (type FixtureDef) to attach properties to object <br>
     /// \b  fd3 -> shape as box , density=30.01 <br> <br>
     /// \b  jd -> (type b2RevoluteJointDef) <br>
     /// \b  jd ->  sbody, body attached to it at point anchor



    //The see-saw system at the bottom
    {
      //The triangle wedge
      b2Body* sbody;
      b2PolygonShape poly;
      b2Vec2 vertices[3];
      vertices[0].Set(-1,0);
      vertices[1].Set(1,0);
      vertices[2].Set(0,1.5);
      poly.Set(vertices, 3);
      b2FixtureDef wedgefd;
      wedgefd.shape = &poly;
      wedgefd.density = 10.0f;
      wedgefd.friction = 0.0f;
      wedgefd.restitution = 0.0f;
      b2BodyDef wedgebd;
      wedgebd.position.Set(30.0f, 0.0f);
      sbody = m_world->CreateBody(&wedgebd);
      sbody->CreateFixture(&wedgefd);

      //The plank on top of the wedge
      b2PolygonShape shape;
      shape.SetAsBox(15.0f, 0.2f);
      b2BodyDef bd2;
      bd2.position.Set(30.0f, 1.5f);
      bd2.type = b2_dynamicBody;
      b2Body* body = m_world->CreateBody(&bd2);
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 1.f;
      fd2->shape = new b2PolygonShape;
      fd2->shape = &shape;
      body->CreateFixture(fd2);

      b2RevoluteJointDef jd;
      b2Vec2 anchor;
      anchor.Set(30.0f, 1.5f);
      jd.Initialize(sbody, body, anchor);
      m_world->CreateJoint(&jd);

      //The light box on the right side of the see-saw
      b2PolygonShape shape2;
      shape2.SetAsBox(2.0f, 2.0f);
      b2BodyDef bd3;
      bd3.position.Set(40.0f, 2.0f);
      bd3.type = b2_dynamicBody;
      b2Body* body3 = m_world->CreateBody(&bd3);
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 30.01f;
      fd3->shape = new b2PolygonShape;
      fd3->shape = &shape2;
      body3->CreateFixture(fd3);
    }


/*! \section the10 car system (3 parts 2 wheels ,1 body)
     *  Variables in this section are:
     *  <br>
     */
     /// \b  poly -> (type b2PolygonShape) to create a concave polygon  <br>
     /// \b  poly -> it is set as box with half-height=4.0f and half-width= 0.2 <br> <br>
     /// \b  wedgefd -> (type FixtureDef) to attach properties to object <br>
     /// \b  wedgefd -> shape=poly(triangle) , density=10.0,friction=0,restitution=0 <br> <br>
     /// \b  wedgebd -> (type b2BodyDef) it has necessary info to make objects <br>
     /// \b  wedgebd ->  position set to (-30-x,2.0-y) <br> <br>
     /// \b  sbody -> (type b2Body*) <br> <br>
     /// \b  circle -> creates a circle shape (type b2CircleShape)  <br>
     /// \b  circle -> it is set as circle with radius=2.0  <br>  <br>
     /// \b  shape -> (type b2PolygonShape) to create a concave polygon <br>
     /// \b  shape -> it is set as box with half-width=15.0f and half-height= 0.2 <br> <br>
     /// \b  bd2 -> (type b2BodyDef) <br>
     /// \b  bd2 -> its position is set to (-26-x,2-y) and set it as dynamic body <br> <br>
     /// \b  fd2 -> (type FixtureDef) to attach properties to object <br>
     /// \b  fd2 -> shape as circle , density=1.0 <br> <br>
     /// \b  body -> (type b2Body*) created using bd2,fd2 <br> <br> 
     /// \b  jd -> (type b2RevoluteJointDef) <br>
     /// \b  jd ->  sbody, body attached to it at point anchor <br> <br>
     /// \b  circle1 -> creates a circle shape (type b2CircleShape)  <br>
     /// \b  circle1 -> it is set as circle with radius=2.0  <br>  <br>
     /// \b  shape1 -> (type b2PolygonShape) to create a concave polygon <br>
     /// \b  shape1 -> it is set as box with half-width=15.0f and half-height= 0.2 <br> <br>
     /// \b  bd21 -> (type b2BodyDef) <br>
     /// \b  bd21 -> its position is set to (-34-x,2-y) and set it as dynamic body <br> <br>
     /// \b  fd21 -> (type FixtureDef) to attach properties to object <br>
     /// \b  fd21 -> shape as circle , density=1.0 <br> <br>
     /// \b  body1 -> (type b2Body*) created using bd2,fd2 <br> <br>
     /// \b  jd -> (type b2RevoluteJointDef) <br>
     /// \b  jd ->  sbody, body1 attached to it at point anchor <br> <br>


///////////////extra////////////////////////////////
    //car
    float x=0,y=0; //use it to shift position of car
    {
      //The axle of car
      b2Body* sbody;
      b2PolygonShape poly;
      poly.SetAsBox(4.0f,0.2f);
      b2FixtureDef wedgefd;
      wedgefd.shape = &poly;
      wedgefd.density = 10.0f;
      wedgefd.friction = 0.0f;
      wedgefd.restitution = 0.0f;
      b2BodyDef wedgebd;
      wedgebd.type = b2_dynamicBody;
      wedgebd.position.Set(-30.0f-x, 2.0f-y);
      sbody = m_world->CreateBody(&wedgebd);
      sbody->CreateFixture(&wedgefd);

      //The wheel of car
      b2CircleShape circle;
      circle.m_radius = 2.0;
      b2BodyDef bd2;
      bd2.position.Set(-26.0f-x, 2.0f-y);
      bd2.type = b2_dynamicBody;
      b2Body* body = m_world->CreateBody(&bd2);
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 1.0f;
      fd2->shape = new b2CircleShape;
      fd2->shape = &circle;
      body->CreateFixture(fd2);

      b2RevoluteJointDef jd;
      b2Vec2 anchor;
      anchor.Set(-26.0f-x, 2.0f-y);
      jd.Initialize(sbody, body, anchor);
      m_world->CreateJoint(&jd);

      //Another wheel of car
      b2CircleShape circle1;
      circle1.m_radius = 2.0;
      b2BodyDef bd21;
      bd21.position.Set(-34.0f-x, 2.0f-y);
      bd21.type = b2_dynamicBody;
      b2Body* body1 = m_world->CreateBody(&bd21);
      b2FixtureDef *fd21 = new b2FixtureDef;
      fd21->density = 1.0f;
      fd21->shape = new b2CircleShape;
      fd21->shape = &circle;
      body1->CreateFixture(fd21);

      b2RevoluteJointDef jd1;
      b2Vec2 anchor1;
      anchor1.Set(-34.0f-x, 2.0f-y);
      jd1.Initialize(sbody, body1, anchor1);
      m_world->CreateJoint(&jd1);

    }

    {
      
      b2EdgeShape shape; 
      shape.Set(b2Vec2(-4.0f, 0.0f), b2Vec2(14.0f, 5.0f));
      b2BodyDef bd; 
      b1 = m_world->CreateBody(&bd); 
      b1->CreateFixture(&shape, 0.0f);
    }
    {
    	 b2Body* spherebody;
	
      b2CircleShape circle;
      circle.m_radius = 0.5;
	
      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 13.5f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;
	
	  b2BodyDef ballbd;
	  ballbd.type = b2_dynamicBody;
	  ballbd.position.Set(10.0f, 5.0f);
	  spherebody = m_world->CreateBody(&ballbd);
	  spherebody->CreateFixture(&ballfd);
	
    }

    ////////////////extra end//////////////////////////////////////////

  }

  sim_t *sim = new sim_t("Dominos", dominos_t::create);
}