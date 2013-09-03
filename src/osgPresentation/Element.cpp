/* -*-c++-*- OpenSceneGraph - Copyright (C) 1998-2013 Robert Osfield
 *
 * This library is open source and may be redistributed and/or modified under
 * the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or
 * (at your option) any later version.  The full license is in LICENSE file
 * included with this distribution, and on the openscenegraph.org website.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * OpenSceneGraph Public License for more details.
*/

#include <osgPresentation/Element>

using namespace osgPresentation;


void Element::traverse(osg::NodeVisitor& nv)
{
    if (nv.getVisitorType()==osg::NodeVisitor::UPDATE_VISITOR)
    {
        osgUtil::UpdateVisitor* uv = dynamic_cast<osgUtil::UpdateVisitor*>(&nv);
        if (uv)
        {
            updateTraversal(*uv);
            return;
        }
    }
    else if (nv.getVisitorType()==osg::NodeVisitor::EVENT_VISITOR)
    {
        osgGA::EventVisitor* ev = dynamic_cast<osgGA::EventVisitor*>(&nv);
        if (ev)
        {
            eventTraversal(*ev);
            return;
        }
    }
    osgPresentation::Group::traverse(nv);
}

void Element::updateTraversal(osgUtil::UpdateVisitor& uv)
{
    OSG_NOTICE<<"Element::updateTraversal()"<<std::endl;
    osgPresentation::Group::traverse(uv);
}

void Element::eventTraversal(osgGA::EventVisitor& ev)
{
    OSG_NOTICE<<"Element::eventTraversal()"<<std::endl;
    osgPresentation::Group::traverse(ev);
}
