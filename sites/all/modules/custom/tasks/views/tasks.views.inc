<?php
/**
 * Implements hook_views_data().
 */
function tasks_views_data()
{
  $data = array();

//  $data['tasks_projects']['table']['group'] = t('Tasks');
//
//  $data['tasks_projects']['table']['base'] = array(
//    'title' => t('Tasks'),
//    'help' => t('Contains tasks we want exposed to Views.'),
//  );

  $data['tasks_project']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['tasks_project']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  $data['tasks_project']['nid'] = array(
    'title' => t('Node ID'),
    'help' => t('The project node ID.'),
    'field' => array(
      'handler' => 'views_handler_field_node',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Project node'),
      'title' => t('Node'),
      'help' => t('Node relationship'),
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_node_nid',
      'numeric' => TRUE,
      'validate type' => 'nid',
    ),
  );

  $data['tasks_project']['uid'] = array(
    'title' => t('User ID'),
    'help' => t('The user ID.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'relationship' => array(
      'base' => 'users',
      'base field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('User '),
      'title' => t('User'),
      'help' => t('User relationship'),
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
      'numeric' => TRUE,
      'validate type' => 'uid',
    ),
  );


  return $data;

}