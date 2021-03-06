//
//  Fodder.cpp
//  Moon3d
//
//  Created by Hao Wu on 2/27/14.
//
//

#include "Fodder.h"
#include "3d/Sprite3D.h"
#include "consts.h"
#include "PublicApi.h"
bool Fodder::init()
{
    _Model = Sprite3D::create("diji1_v001.obj", "diji02_v002_1024.png");
    if(_Model)
    {
        _Model->setScale(10);
        addChild(_Model);
        _Model->setRotation3D(Vertex3F(90,0,0));
                static_cast<Sprite3D*>(_Model)->setOutline(0.3, Color3B(255,0,0));
        _radius=40;
        _type = kEnemy;
        
        //this->schedule(schedule_selector(Fodder::acrobacy) , 0.1, -1, 0.0);
        this->scheduleUpdate();
        return true;
    }
    return false;
}

void Fodder::move(float duration, const Point& position)
{
    MoveTo*  MoveDownOutScreen = MoveTo::create(duration,position);
    
    CallFuncN *callBack = CallFuncN::create(callfunc_selector(Fodder::RemoveFodder));
    
    this->runAction(Sequence::create(MoveDownOutScreen,callBack,NULL));
}
/*
void Fodder::acrobacy(float dt)
{
   
}
 */
void Fodder::update(float dt)
{
    this->setRotation3D(Vertex3F(0,smoothAngle,0));
    smoothAngle+=rollSpeed;
}
void Fodder::RemoveFodder()
{
    this->removeFromParentAndCleanup(true);
    //this->removeFromParent();
}
