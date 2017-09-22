<?php

/**
 * Form definition for adding / editing a project.
 */


function tasks_form($form, &$form_state, $tasks = NULL) {
  
   // kpr($tasks);
 
  global $user;
  $form['uid'] = array(
    '#title'=> t ("User "),
    '#default_value' => isset($tasks->uid) ? $tasks->uid : $tasks->uid = $user->uid,
  );
 
  $form['nid'] = array(
    '#title'=> t ("Project "),
    '#type' => 'entityreference',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('Project'),
    '#era_query_settings' => array(
      'field_conditions' => array(
        array('field_developers', 'target_id', $user->uid),
      ),
    ),
    '#required' => TRUE,
    '#default_value' => isset($tasks->nid) ? $tasks->nid : '',
  );
  $form['start_date'] = array(
    '#title' => t('Start'),
    '#type' => 'date_select',
    '#date_format'=> 'H:i',    
    // Provide a default date in the format YYYY-MM-DD HH:MM:SS !!!
    '#default_value' => isset($tasks->start_date) ? date('Y-m-d H:i:s', $tasks->start_date) : '',    
    '#required' => TRUE,
   );


  $form['end_date'] = array(
    '#title' => t('End'),
    '#type' => 'date_select',
    '#date_format'=> 'H:i',
    '#default_value' => isset($tasks->end_date) ? date('Y-m-d H:i:s', $tasks->end_date ): '',
    '#required' => TRUE,
  );

  $form['task_date'] = array(
    '#title'=> t('Task date'),
    '#type' => 'date_popup',
    '#date_format' => 'Y-m-d',
    '#default_value' => isset($tasks->task_date) ? date('Y-m-d H:i:s', $tasks->task_date) : '',
    '#required' => TRUE,
    );

  $form['created'] = array(
    '#title' => t('Create'),
    '#default_value' => isset($tasks->created) ? $tasks->created : $tasks->created = time(),
  );

 
  $form['approval'] = array(
    '#title' => t('Approving'),
    '#type' => 'checkboxes',
    '#options' => drupal_map_assoc(array(t('Approve'),t('Decline'))),
    '#default-value' => isset($tasks->approval) ? $tasks->approval : '',
    '#tree' => true,
    '#access' => false,
   );
  
   if (in_array('ProjectManager', array_values($user->roles))) {
    $form['approval']['#access'] = true;
   }
  

  $from['updated'] = array(
    '#title' => t('Update on'),
    '#value' => isset($tasks->tid) ? $tasks->updated = time() : '',
  );

  $form['task_description'] = array(
    '#title' => t('Task name'),
    '#type' => 'textfield',
    '#default_value' => isset($tasks->task_description) ? $tasks->task_description : '',
    '#required' => TRUE,
  );

  $form['details'] = array(
    '#title' => t('Task details'),
    '#type' => 'textarea',
    '#default_value' => isset($tasks->details) ? $tasks->details : '',

  );

  field_attach_form('tasks', $tasks, $form, $form_state);

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => isset($tasks->tid) ? t('Update task') : t('Save task'),
    '#weight' => 50,
  );

  return $form;
}

/**
 * Submit handler for the project add/edit form.
 */
function tasks_form_submit($form, &$form_state) {

  $tasks = entity_ui_form_submit_build_entity($form, $form_state);

//  global $user;
//  $tasks->uid = $user->uid;

  $tasks->start_date = strtotime($tasks->start_date);
  $tasks->end_date = strtotime($tasks->end_date);
  $tasks->task_date = strtotime($tasks->task_date);
  $project = array_values($tasks->nid);
  $tasks->nid = $project[0];

  $time_spent = time_spent($tasks->start_date, $tasks->end_date);

  $tasks->time_spent = $time_spent;

  $task_status = array_values($tasks->approval);
  $value = substr(implode(",", $task_status), 0, -2);
    
  switch($value) {
      case "Approve":
      $tasks->approval = 1;
      break;
    case "Decline":
      $tasks->approval = -1;
      break;
    case 0:
      $tasks->approval = 0;
      break;
  }
 
  $tasks->save();
  drupal_set_message(t('The task has been saved.'));
  $form_state['redirect'] = '/tasks';

}

function time_spent ($start, $finish) {
  $Hours = floor(($finish - $start) / 3600);
  $minutes = floor((($finish - $start) / 60) % 60);
  $hrs = strval($Hours);
  $min = strval($minutes);
  $time = $hrs . "H:" . $min . "m";

  return $time;
}

