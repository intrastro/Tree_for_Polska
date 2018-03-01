#include <iostream>
#include <thread>
#include "windows.h"
#include <conio.h>
#include <stdio.h>
#include <mutex>
#pragma once
using namespace std;

#define development_stack FALSE

struct Node
        {
        int symbol;
        Node* link_right;
        Node* link_left;
        Node* link_back;
        };
typedef Node *PNode;


template <typename l_type> class treeer
        {
        private:
                PNode Root;
                PNode Current ;

        public:
                treeer ()
                        {
                        Root = nullptr;
                        Current = Root;

                        #if development_stack
                        std::cout << "created" << std::endl;
                        #endif
                        }

                        ~treeer ()
                        {
                        #if development_stack
                        std::cout << std::endl;
                        std::cout << "deleted" << std::endl;
                        #endif
                        }

                bool set_current_branch (char key)
                        {
                        if (Current != nullptr)
                                {
                                if (key == 'r')
                                        {
                                        if (Current -> link_right != nullptr)
                                                {
                                                Current = Current -> link_right;
                                                }
                                        }
                                 else if (key == 'l')
                                        {
                                        if (Current -> link_left != nullptr)
                                                {
                                                Current = Current -> link_left;
                                                }
                                        }
                                else if (key == 'b')
                                        {
                                        if (Current -> link_back != nullptr)
                                                {
                                                Current = Current -> link_back;
                                                }
                                        }
                                else
                                        {
                                        return FALSE;
                                        }

                                return TRUE;
                                }
                        else
                                {
                                return FALSE;
                                }
                        }

                bool create_current_child (char k, int key)
                        {
                        if (Current != nullptr)
                                {
                                if (key == 'r')
                                        {
                                        if (Current -> link_right  == nullptr)
                                                {
                                                Current -> link_right = new Node;

                                                Current -> link_right -> link_right = nullptr;

                                                Current -> link_right -> link_left = nullptr;

                                                Current -> link_right -> link_back = Current;

                                                Current -> link_right -> symbol = key;
                                                }
                                        }
                                 else if (key == 'l')
                                        {
                                        if (Current -> link_left == nullptr)
                                                {
                                                Current -> link_left  = new Node;

                                                Current -> link_left  -> link_right = nullptr;

                                                Current -> link_left  -> link_left = nullptr;

                                                Current -> link_left  -> link_back = Current;

                                                Current -> link_left -> symbol = key;
                                                }
                                        }
                                else
                                        {
                                        return FALSE;
                                        }

                                return TRUE;
                                }
                        else
                                {
                                return FALSE;
                                }
                        }

                bool delete_current (PNode vertex)
                        {
                        if (vertex != nullptr)
                                {
                                //cycle
                                //while current->left&&current->right != null, so, delete current (right_tree, right_tree)
                               if (vertex -> right != nullptr)
                                        {
                                        delete_current (vertex -> right);
                                        }
                               else if (vertex -> left != nullptr)
                                        {
                                        delete_current (vertex -> left);
                                        }
                                else
                                        {
                                        delete vertex;
                                        }


                                return TRUE;
                                }
                        else
                                {
                                return FALSE;
                                }
                        }







        };





