<?php


function tasks_entity_property_info() {

  $info = array();

  $info['tasks']['properties']['tid'] = array(
    'label' => t('Task ID'),
    'type' => 'integer',
    'schema field' => 'tid',
  );

  $info['tasks']['properties']['start_date'] = array(
    'label' => t('Start task'),
    'description' => t('Start time for task'),
    'type' => 'date',
    'schema field' => 'start_date',
  );
  $info['tasks']['properties']['end_date'] = array(
    'label' => t('End task'),
    'description' => t('Finish time for task'),
    'type' => 'date',
    'schema field' => 'end_date',
  );
  $info['tasks']['properties']['task_date'] = array(
    'label' => t('Date for task'),
    'description' => t('Date of task'),
    'type' => 'date',
    'schema field' => 'task_date',
  );
  $info['tasks']['properties']['created'] = array(
    'label' => t('Created task on'),
    'description' => t('Date of task creation'),
    'type' => 'date',
    'schema field' => 'created',
  );
  $info['tasks']['properties']['updated'] = array(
    'label' => t('Updated task on'),
    'description' => t('Date of task update'),
    'type' => 'date',
    'schema field' => 'updated',
  );
  $info['tasks']['properties']['approval'] = array(
    'label' => t('Need approval'),
    'description' => t('Status for task'),
    'type' => 'integer',
    'schema field' => 'approval',
  );
  $info['tasks']['properties']['task_description'] = array(
    'label' => t('Task '),
    'help' => t('Name for task'),
    'type' => 'text',
    'schema field' => 'task_description',
  );
  $info['tasks']['properties']['details'] = array(
    'label' => t('Task details'),
    'description' => t('Details for task'),
    'type' => 'text',
    'schema field' => 'details',
  );
  $info['tasks']['properties']['time_spent'] = array(
    'label' => t('Time spent '),
    'description' => t('Required time for the task'),
    'type' => 'text',
    'schema field' => 'time_spent',
  );


  return $info;
}
